// Copyright 2019 the donut authors. See AUTHORS.md

#include <Character.h>
#include <CharacterController.h>
#include <Game.h>
#include <P3D/p3d.generated.h>
#include <P3D/P3DFile.h>
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
			Game::GetInstance().GetResourceManager().LoadShader(*P3D::Shader::Load(*chunk));
			break;
		case P3D::ChunkType::Texture:
			Game::GetInstance().GetResourceManager().LoadTexture(*P3D::Texture::Load(*chunk));
			break;
		case P3D::ChunkType::PolySkin:
			_skinModel->LoadPolySkin(*P3D::PolySkin::Load(*chunk));
			break;
		case P3D::ChunkType::Skeleton:
			loadSkeleton(*P3D::Skeleton::Load(*chunk));
			break;
		default:
			fmt::print("unhandled chunk {1} in character {0}\n", name, chunk->GetType());
			break;
		}
	}
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
	const auto localPosition = _position - glm::vec3(0.0f, _characterController->GetShape().getHalfHeight() * 2, 0.0f);
	const glm::mat4 mvp      = glm::translate(viewProjection, localPosition) * glm::toMat4(_rotation);

	shaderProgram.Bind(); // todo optimize: should already be bound?
	shaderProgram.SetUniformValue("viewProj", mvp);
	shaderProgram.SetUniformValue("diffuseTex", 0); // todo optimize: should already be set
	shaderProgram.SetUniformValue("boneBuffer", 1); // todo optimize: should already be set

	// bind the bone buffer to tex1
	glActiveTexture(GL_TEXTURE1);
	_boneBuffer->Bind();

	_skinModel->Draw();
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
	const auto& animGroupList = p3dAnim.GetGroupList();
	if (!animGroupList) return;

	auto animation = std::make_unique<SkinAnimation>(
	    p3dAnim.GetName(),
	    p3dAnim.GetNumFrames() / p3dAnim.GetFrameRate(),
	    static_cast<int32_t>(p3dAnim.GetNumFrames()),
	    p3dAnim.GetFrameRate());

	const auto& groups = animGroupList->GetGroups();
	std::map<std::string, size_t> groupNameIndex;
	for (const auto& group : groups)
	{
		groupNameIndex.insert({ group->GetName(), groupNameIndex.size() });
	}

	for (auto const& joint : _skeletonJoints)
	{
		auto track = std::make_unique<SkinAnimation::Track>(joint.name);

		const auto& jointRestPose    = joint.restPose;
		const auto& jointTranslation = jointRestPose[3];
		const auto& jointRotation    = glm::quat_cast(jointRestPose);

		if (groupNameIndex.find(joint.name) == groupNameIndex.end())
		{
			track->AddTranslationKey(0, jointTranslation);
			track->AddRotationKey(0, jointRotation);
		}
		else
		{
			const auto& animGroup = groups.at(groupNameIndex.at(joint.name));
			const auto& vector2Channel              = animGroup->GetVector2ChannelsValue("TRAN");
			const auto& vector3Channel              = animGroup->GetVector3ChannelsValue("TRAN");
			const auto& quaternionChannel           = animGroup->GetQuaternionChannelsValue("ROT");
			const auto& compressedQuaternionChannel = animGroup->GetCompressedQuaternionChannelsValue("ROT");

			if (vector3Channel)
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

			if (compressedQuaternionChannel)
			{
				const auto& frames = compressedQuaternionChannel->GetFrames();
				const auto& values = compressedQuaternionChannel->GetValues();

				for (std::size_t i = 0; i < compressedQuaternionChannel->GetNumFrames(); ++i)
				{
					const uint64_t& value = values[i];
					float z = (int16_t)((value >> 48) & 0xFFFF) / (float)0x7FFF;
					float y = (int16_t)((value >> 32) & 0xFFFF) / (float)0x7FFF;
					float x = (int16_t)((value >> 16) & 0xFFFF) / (float)0x7FFF;
					float w = (int16_t)(value & 0xFFFF) / (float)0x7FFF;

					track->AddRotationKey(frames[i], glm::quat(w, x, y, z));
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
