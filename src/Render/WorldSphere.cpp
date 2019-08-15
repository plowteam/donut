// Copyright 2019 the donut authors. See AUTHORS.md

#include <Game.h>
#include <Render/LineRenderer.h>
#include <Render/SkinAnimation.h>
#include <Render/WorldSphere.h>
#include <Skeleton.h>

namespace Donut
{

WorldSphere::WorldSphere(const P3D::WorldSphere& worldSphere):
    _name(worldSphere.GetName())
{
	auto meshes     = std::unordered_map<std::string, std::unique_ptr<Mesh>>(worldSphere.GetMeshCount());
	auto billboards = std::unordered_map<std::string, std::unique_ptr<BillboardBatch>>(worldSphere.GetBillboardCount());

	for (auto const& p3dmesh : worldSphere.GetMeshes())
	{
		auto mesh = std::make_unique<Mesh>(*p3dmesh);
		mesh->Commit();
		meshes[p3dmesh->GetName()] = std::move(mesh);
	}
	
	//for (auto const& billboard : worldSphere.GetBillboards())
	//	billboards.emplace_back(std::make_unique<BillboardBatch>(*billboard));

	auto const& compositeDrawableList = worldSphere.GetCompositeDrawable()->GetPropList()->GetProps();
	for (auto const& p3dprop : compositeDrawableList)
	{
		if (meshes.find(p3dprop->GetName()) == meshes.end())
			continue;

		_props.emplace_back(std::move(meshes.at(p3dprop->GetName())), p3dprop->GetSkeletonJoint());
	}

	// should be horizon1
	_skeleton = std::make_unique<Skeleton>(*worldSphere.GetSkeletons()[0]);

	// load animation
	auto const& p3dAnim = *worldSphere.GetAnimation();
	_animation          = std::make_unique<SkinAnimation>(
        p3dAnim.GetName(),
        p3dAnim.GetNumFrames() / p3dAnim.GetFrameRate(),
        static_cast<int32_t>(p3dAnim.GetNumFrames()),
        p3dAnim.GetFrameRate());

	const auto& animGroupList = p3dAnim.GetGroupList();
	const auto& groups        = animGroupList->GetGroups();
	std::map<std::string, size_t> groupNameIndex;
	for (const auto& group : groups)
	{
		groupNameIndex.insert({ group->GetName(), groupNameIndex.size() });
	}

	for (auto const& joint : _skeleton->GetJoints())
	{
		auto track = std::make_unique<SkinAnimation::Track>(joint.name);

		const auto& jointRestPose    = joint.rest;
		const auto& jointTranslation = jointRestPose[3];
		const auto& jointRotation    = glm::quat_cast(jointRestPose);

		if (groupNameIndex.find(joint.name) == groupNameIndex.end())
		{
			track->AddTranslationKey(0, jointTranslation);
			track->AddRotationKey(0, jointRotation);
		}
		else
		{
			const auto& animGroup                   = groups.at(groupNameIndex.at(joint.name));
			const auto& vector2Channel              = animGroup->GetVector2ChannelsValue("TRAN");
			const auto& vector3Channel              = animGroup->GetVector3ChannelsValue("TRAN");
			const auto& quaternionChannel           = animGroup->GetQuaternionChannelsValue("ROT");
			const auto& compressedQuaternionChannel = animGroup->GetCompressedQuaternionChannelsValue("ROT");

			if (vector2Channel)
			{
				const auto& frames = vector2Channel->GetFrames();
				const auto& values = vector2Channel->GetValues();
				const auto& constants = vector2Channel->GetConstants();

				for (std::size_t i = 0; i < vector2Channel->GetNumFrames(); ++i)
				{
					track->AddTranslationKey(frames[i], constants + glm::vec3(values[i].x, 0.0f, values[i].y));
				}
			}
			else if (vector3Channel)
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

			if (quaternionChannel)
			{
				const auto& frames = quaternionChannel->GetFrames();
				const auto& values = quaternionChannel->GetValues();

				for (std::size_t i = 0; i < quaternionChannel->GetNumFrames(); ++i)
				{
					auto q = values[i];
					track->AddRotationKey(frames[i], glm::quat(q.x, q.y, q.z, q.w));
				}
			}
			else if (compressedQuaternionChannel)
			{
				const auto& frames = compressedQuaternionChannel->GetFrames();
				const auto& values = compressedQuaternionChannel->GetValues();

				for (std::size_t i = 0; i < compressedQuaternionChannel->GetNumFrames(); ++i)
				{
					const uint64_t& value = values[i];
					float z               = (int16_t)((value >> 48) & 0xFFFF) / (float)0x7FFF;
					float y               = (int16_t)((value >> 32) & 0xFFFF) / (float)0x7FFF;
					float x               = (int16_t)((value >> 16) & 0xFFFF) / (float)0x7FFF;
					float w               = (int16_t)(value & 0xFFFF) / (float)0x7FFF;

					track->AddRotationKey(frames[i], glm::quat(w, x, y, z));
				}
			}
			else
			{
				track->AddRotationKey(0, jointRotation);
			}
		}

		_animation->AddTrack(track);
	}

	_animTime = 0.0;

	// worldSphere.GetCompositeDrawable

	// Animation
	// Skeleton
	// OldBillboardQuadGroup
	// Mesh
	// Composite Drawable
	// Old Frame Controller
	// Multi Controller
	// Skeleton
	// Lens Flare
}

void WorldSphere::Draw(GL::ShaderProgram& shader, const glm::mat4& viewProj, bool opaque) const
{
	for (auto const& prop : _props)
	{
		const auto& joint = _skeleton->GetJoint(prop.skeleton_joint);
		shader.SetUniformValue("viewProj", viewProj * joint.finalGlobal);
		prop.mesh->Draw(shader, opaque);
	}

	shader.SetUniformValue("viewProj", viewProj);
}

void WorldSphere::Update(double deltatime)
{
	_animTime += deltatime;

	if (_animation != nullptr)
		_skeleton->UpdatePose(*_animation, _animTime);

	Game::GetInstance().GetLineRenderer().DrawSkeleton(glm::vec3(0.0, 0.0, 0.0), *_skeleton);
}

} // namespace Donut
