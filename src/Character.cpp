#include <Character.h>
#include <CharacterController.h>
#include <Game.h>
#include <P3D/Animation.h>
#include <P3D/P3DFile.h>
#include <P3D/PolySkin.h>
#include <P3D/Skeleton.h>
#include <P3D/Texture.h>
#include <Physics/BulletCast.h>
#include <Render/OpenGL/ShaderProgram.h>
#include <Render/SkinModel.h>
#include <fmt/format.h>

namespace Donut
{

Character::Character(std::string name):
    _name(std::move(name)), _position(glm::vec3(0.0f)), _rotation(glm::quat())
{
	_characterController = std::make_unique<CharacterController>(this, &Game::GetInstance().GetWorldPhysics());
	// _skinModel = std::make_unique<SkinModel>();
}

void Character::LoadModel(const std::string& name)
{
	// we need to empty
	_skinModel.reset(new SkinModel());

	_modelName = name;

	const std::string modelPath = fmt::format("art/chars/{0}_m.p3d", name);
	const P3D::P3DFile p3d(modelPath);

	for (const auto& chunk : p3d.GetRoot().GetChildren())
	{
		switch (chunk->GetType())
		{
		case P3D::ChunkType::Shader:
		{
			const auto shader                    = P3D::Shader::Load(*chunk);
			_shaderTextureMap[shader->GetName()] = shader->GetTexture();
			break;
		}
		case P3D::ChunkType::Texture:
		{
			auto texture                    = P3D::Texture::Load(*chunk);
			auto texdata                    = texture->GetData();
			_textureMap[texture->GetName()] = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, texdata.data.data());
			break;
		}
		case P3D::ChunkType::PolySkin:
		{
			auto const polySkin = P3D::PolySkin::Load(*chunk);
			_skinModel->LoadPolySkin(*polySkin);
			_boundingBox = polySkin->GetBoundingBox();
			_boundingSphere = polySkin->GetBoundingSphere();
			break;
		}
		case P3D::ChunkType::Skeleton:
			loadSkeleton(*P3D::Skeleton::Load(*chunk));
			break;
		default: break;
		}
	}

	_characterController->UpdateBoundingBox();
}

void Character::LoadAnimations(const std::string& name)
{
	_animations.clear();

	const std::string animPath = fmt::format("art/chars/{0}_a.p3d", name);
	//const std::string choPath = fmt::format("art/chars/{0}.cho", name);

	if (!std::filesystem::exists(animPath)) return;

	const P3D::P3DFile p3d(animPath);
	for (const auto& chunk : p3d.GetRoot().GetChildren())
	{
		if (!chunk->IsType(P3D::ChunkType::Animation))
			continue;

		addAnimation(*P3D::Animation::Load(*chunk));
	}

	// default to using the first in the map
	SetAnimation(_animations.begin()->first);
}

void Character::Draw(const glm::mat4& viewProjection, GL::ShaderProgram& shaderProgram, const ResourceManager& rm)
{
	const auto localPosition = _position - _boundingSphere.GetCenter();
	const glm::mat4 mvp      = glm::translate(viewProjection, localPosition) * glm::toMat4(_rotation);

	shaderProgram.Bind(); // todo optimize: should already be bound?
	shaderProgram.SetUniformValue("viewProj", mvp);
	shaderProgram.SetUniformValue("diffuseTex", 0); // todo optimize: should already be set
	shaderProgram.SetUniformValue("boneBuffer", 1); // todo optimize: should already be set

	// bind the bone buffer to tex1
	glActiveTexture(GL_TEXTURE1);
	_boneBuffer->Bind();

	_skinModel->Draw(rm, _shaderTextureMap, _textureMap);
}

void Character::SetAnimation(const std::string& animationName)
{
	if (_animations.find(animationName) == _animations.end())
		return;

	_currentAnimation = _animations.at(animationName).get();
	_animName         = animationName;

	_animTime = 0.0;
	updateAnimation(*_currentAnimation, 0.0);
}

void Character::Update(double deltatime)
{
	// update bone buffers
	_animTime += deltatime;

	if (_currentAnimation != nullptr)
		updateAnimation(*_currentAnimation, _animTime);
}

void Character::SetPosition(const glm::vec3& position)
{
	_position = position;
	_characterController->warp(BulletCast<btVector3>(position));
}
void Character::SetRotation(const glm::quat& rotation)
{
	_rotation = rotation;
}

void Character::loadSkeleton(const P3D::Skeleton& skeleton)
{
	auto& joints = skeleton.GetJoints();

	_boneBuffer = std::make_unique<GL::TextureBuffer>();
	_boneMatrices.resize(joints.size(), glm::mat4(1.0f));  // Skeleton matrices, these don't change
	_poseMatrices.resize(joints.size(), glm::mat4(1.0f));  // Pose matrices, these change with animation
	_finalMatrices.resize(joints.size(), glm::mat4(1.0f)); // Final matrices, rest pose matrix inverse * pose matrix

	for (uint32_t jointIndex = 0; jointIndex < joints.size(); ++jointIndex)
		_boneMatrices[jointIndex] = _boneMatrices[joints[jointIndex]->GetParent()] * joints[jointIndex]->GetRestPose();

	_boneBuffer->SetBuffer(_finalMatrices.data(), _finalMatrices.size() * sizeof(glm::mat4));

	_skeletonJoints.clear(); // clear if we had an old skeleton
	_skeletonJoints.reserve(joints.size());
	for (auto const& joint : joints)
		_skeletonJoints.emplace_back(joint->GetName(), joint->GetParent(), joint->GetRestPose());
}

void Character::addAnimation(const P3D::Animation& p3dAnim)
{
	const auto animGroupList = p3dAnim.GetGroupList();
	if (animGroupList == nullptr) return;

	auto animation = std::make_unique<SkinAnimation>(
	    p3dAnim.GetName(),
	    p3dAnim.GetNumFrames() / p3dAnim.GetFrameRate(),
	    static_cast<int32_t>(p3dAnim.GetNumFrames()),
	    p3dAnim.GetFrameRate());

	for (auto const& joint : _skeletonJoints)
	{
		auto track = std::make_unique<SkinAnimation::Track>(joint.name);

		const auto& jointRestPose    = joint.restPose;
		const auto& jointTranslation = jointRestPose[3];
		const auto& jointRotation    = glm::quat_cast(jointRestPose);

		const auto animGroup = animGroupList->GetGroup(joint.name);
		if (animGroup == nullptr)
		{
			track->AddTranslationKey(0, jointTranslation);
			track->AddRotationKey(0, jointRotation);
		}
		else
		{
			const auto vector2Channel              = animGroup->GetVector2Channel();
			const auto vector3Channel              = animGroup->GetVector3Channel();
			const auto quaternionChannel           = animGroup->GetQuaternionChannel();
			const auto compressedQuaternionChannel = animGroup->GetCompressedQuaternionChannel();

			if (vector3Channel != nullptr)
			{
				const auto& frames = vector3Channel->GetFrames();
				const auto& values = vector3Channel->GetValues();

				for (std::size_t i = 0; i < vector3Channel->GetNumFrames(); ++i)
				{
					track->AddTranslationKey(frames[i], values[i]);
				}
			}
			else
			{
				track->AddTranslationKey(0, jointTranslation);
			}

			if (compressedQuaternionChannel != nullptr)
			{
				const auto& frames = compressedQuaternionChannel->GetFrames();
				const auto& values = compressedQuaternionChannel->GetValues();

				for (std::size_t i = 0; i < compressedQuaternionChannel->GetNumFrames(); ++i)
				{
					track->AddRotationKey(frames[i], values[i]);
				}
			}
			else
			{
				track->AddRotationKey(0, jointRotation);
			}
		}

		animation->AddTrack(track);
	}

	_animations[p3dAnim.GetName()] = std::move(animation);
}

void Character::updateAnimation(SkinAnimation& animation, double time)
{
	time *= animation.GetFrameRate();

	_poseMatrices[0] = glm::mat4(1.0f);

	for (uint32_t jointIndex = 0; jointIndex < _skeletonJoints.size(); ++jointIndex)
		_poseMatrices[jointIndex] = _poseMatrices[_skeletonJoints[jointIndex].parent] * animation.Evaluate(jointIndex, static_cast<float>(time));
	for (uint32_t jointIndex = 0; jointIndex < _skeletonJoints.size(); ++jointIndex)
		_finalMatrices[jointIndex] = _poseMatrices[jointIndex] * glm::inverse(_boneMatrices[jointIndex]);
	_boneBuffer->SetBuffer(_finalMatrices.data(), _finalMatrices.size() * sizeof(glm::mat4));
}

} // namespace Donut
