#include <Render/SkinModel.h>
#include <P3D/p3d.generated.h>

namespace Donut
{

void SkinModel::LoadPolySkin(const P3D::PolySkin& polySkin)
{
	// todo: reset the _vertexBuffer & _indexBuffer

	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;
	std::size_t vertOffset = 0, idxOffset = 0;

	for (auto const& prim : polySkin.GetPrimitiveGroups())
	{
		const auto primVerts         = prim->GetVertices();
		const auto primUV            = prim->GetUvs(0);
		const auto primNormals       = prim->GetNormals();
		const auto primIndices       = prim->GetIndices();
		const auto primWeights       = prim->GetWeightList();
		const auto primMatrixList    = prim->GetMatrixList();
		const auto primMatrixPalette = prim->GetMatrixPalette();

		// todo: there are flags on P3D::PrimGroup to determine this:
		const bool primHasBoneIndices = !primMatrixList.empty() && !primMatrixPalette.empty();
		const bool primHasWeights     = !primWeights.empty();

		for (uint32_t i = 0; i < primVerts.size(); i++)
		{
			auto boneIndices = glm::ivec3(0.0);

			if (primHasBoneIndices)
			{
				const auto m = primMatrixList[i];
				auto i0 = (m >> 24) & 0xFF;
				auto i1 = (m >> 16) & 0xFF;
				auto i2 = (m >> 8) & 0xFF;
				auto i3 = m & 0xFF;

				boneIndices = glm::ivec3(
					primMatrixPalette[i0],
					primMatrixPalette[i1],
					primMatrixPalette[i2]);
			}

			const auto weight = primHasWeights ? primWeights[i] : glm::vec3(1, 0, 0);
			const auto uv     = glm::vec2(primUV[i].x, 1.0f - primUV[i].y); // turn that frown upside down :)

			vertices.emplace_back(primVerts[i], primNormals[i], uv, weight, boneIndices);
		}

		// copy over indices and offset by the prim groups vertices
		for (auto idx : primIndices)
			indices.emplace_back(idx + static_cast<uint32_t>(vertOffset));

		GLenum mode = GL_TRIANGLE_STRIP;
		switch ((P3D::PrimitiveType)prim->GetPrimType())
		{
		case P3D::PrimitiveType::TriangleStrip: mode = GL_TRIANGLE_STRIP; break;
		case P3D::PrimitiveType::TriangleList: mode = GL_TRIANGLES; break;
		case P3D::PrimitiveType::LineStrip: mode = GL_LINE_STRIP; break;
		case P3D::PrimitiveType::LineList: mode = GL_LINES; break;
		}
		_primGroups.emplace_back(mode, prim->GetShaderName(), idxOffset, primIndices.size());

		vertOffset += primVerts.size();
		idxOffset += primIndices.size();
	}

	GL::ArrayElement vertexLayout[] = {
		GL::ArrayElement(0, 3, GL::AE_FLOAT, sizeof(Vertex), offsetof(Vertex, pos)),
		GL::ArrayElement(1, 3, GL::AE_FLOAT, sizeof(Vertex), offsetof(Vertex, normal)),
		GL::ArrayElement(2, 2, GL::AE_FLOAT, sizeof(Vertex), offsetof(Vertex, uv)),
		GL::ArrayElement(3, 3, GL::AE_FLOAT, sizeof(Vertex), offsetof(Vertex, boneWeights)),
		GL::ArrayElement(4, 3, GL::AE_INT, sizeof(Vertex), offsetof(Vertex, boneIndices)),
	};

	_vertexBuffer = std::make_unique<GL::VertexBuffer>(vertices.data(), vertices.size(), sizeof(Vertex));
	_indexBuffer  = std::make_unique<GL::IndexBuffer>(indices.data(), indices.size(), GL_UNSIGNED_INT);

	_vertexBinding = std::make_unique<GL::VertexBinding>();
	_vertexBinding->Create(vertexLayout, 5, *_vertexBuffer, *_indexBuffer, GL::AE_UINT);
}

/*void SkinModel::LoadSkeleton(P3D::Skeleton& skeleton)
{
	auto& joints = skeleton.GetJoints();

	_boneBuffer = std::make_unique<GL::TextureBuffer>();
	_boneMatrices.resize(joints.size(), glm::mat4(1.0f));  // Skeleton matrices, these don't change
	_poseMatrices.resize(joints.size(), glm::mat4(1.0f));  // Pose matrices, these change with animation
	_finalMatrices.resize(joints.size(), glm::mat4(1.0f)); // Final matrices, rest pose matrix inverse * pose matrix

	for (uint32_t jointIndex = 0; jointIndex < joints.size(); ++jointIndex)
		_boneMatrices[jointIndex] = _boneMatrices[joints[jointIndex]->GetParent()] * joints[jointIndex]->GetRestPose();

	_boneBuffer->SetBuffer(_finalMatrices.data(), _finalMatrices.size() * sizeof(glm::mat4));
}

void SkinModel::UpdateAnimation(SkinAnimation& anim, double time)
{
	// ideally SkinModel wouldn't own it's _boneBuffer
	time *= anim.GetFrameRate();

	_poseMatrices[0] = glm::mat4(1.0f);

	for (uint32_t jointIndex = 0; jointIndex < _skeletonJoints.size(); ++jointIndex)
		_poseMatrices[jointIndex] = _poseMatrices[_skeletonJoints[jointIndex].parent] * anim.Evaluate(jointIndex, static_cast<float>(time));

	for (uint32_t jointIndex = 0; jointIndex < _skeletonJoints.size(); ++jointIndex)
		_finalMatrices[jointIndex] = _poseMatrices[jointIndex] * glm::inverse(_boneMatrices[jointIndex]);

	_boneBuffer->SetBuffer(_finalMatrices.data(), _finalMatrices.size() * sizeof(glm::mat4));
}*/

void SkinModel::Draw(const ResourceManager& rm, const std::unordered_map<std::string, std::string>& shaderMap, const std::unordered_map<std::string, std::unique_ptr<GL::Texture2D>>& textureMap)
{
	_vertexBinding->Bind();

	glActiveTexture(GL_TEXTURE0);
	for (auto const& primGroup : _primGroups)
	{
		auto const& textureName = shaderMap.at(primGroup.shaderName);

		if (textureMap.find(textureName) == textureMap.end())
			rm.GetTexture(textureName).Bind();
		else
			textureMap.at(textureName)->Bind();

		glDrawElements(primGroup.mode, primGroup.indicesCount, _indexBuffer->GetType(), reinterpret_cast<const void*>(primGroup.indicesOffset * 4));
	}

	_vertexBinding->Unbind();
}

/*void SkinModel::LoadAnimations(const std::string& filename)
{
	if (!std::filesystem::exists(filename)) return;

	const P3D::P3DFile animP3D(filename);
	for (const auto& chunk : animP3D.GetRoot().GetChildren())
	{
		switch (chunk->GetType())
		{
		case P3D::ChunkType::Animation:
		{
			AddAnimation(*P3D::Animation::Load(*chunk));
			break;
		}
		default: break;
		}
	}

	updateAnimation(_animIndex, 0.0f);
}

void SkinModel::AddAnimation(const P3D::Animation& p3dAnim)
{
	const auto animGroupList = p3dAnim.GetGroupList();
	if (animGroupList == nullptr) return;

	auto animation = std::make_unique<SkinAnimation>(
	    p3dAnim.GetName(),
	    p3dAnim.GetNumFrames() / p3dAnim.GetFrameRate(),
	    static_cast<int32_t>(p3dAnim.GetNumFrames()),
	    p3dAnim.GetFrameRate());

	auto const& joints = _skeleton->GetJoints();

	for (auto const& joint : _skeleton->GetJoints())
	{
		auto track = std::make_unique<SkinAnimation::Track>(joint->GetName());

		const auto& jointRestPose    = joint->GetRestPose();
		const auto& jointTranslation = jointRestPose[3];
		const auto& jointRotation    = glm::quat_cast(jointRestPose);

		const auto animGroup = animGroupList->GetGroup(joint->GetName());
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

				for (size_t i = 0; i < vector3Channel->GetNumFrames(); ++i)
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

				for (size_t i = 0; i < compressedQuaternionChannel->GetNumFrames(); ++i)
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
}*/

} // namespace Donut
