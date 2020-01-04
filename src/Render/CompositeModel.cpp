// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include <Game.h>
#include <P3D/P3D.generated.h>
#include <P3D/P3DFile.h>
#include <Render/CompositeModel.h>
#include "Core/FileSystem.h"
#include <iostream>

namespace Donut
{
CompositeModel_Chunk::CompositeModel_Chunk(const P3D::P3DChunk& chunk)
{
	for (const auto& child : chunk.GetChildren())
	{
		switch (child->GetType())
		{
		case P3D::ChunkType::CompositeDrawable:
		{
			_drawables.push_back(P3D::CompositeDrawable::Load(*child));
			break;
		}
		case P3D::ChunkType::Skeleton:
		{
			_skeletons.push_back(P3D::Skeleton::Load(*child));
			break;
		}
		case P3D::ChunkType::Geometry:
		{
			_meshes.push_back(P3D::Geometry::Load(*child));
			break;
		}
		case P3D::ChunkType::Shader:
		{
			_shaders.push_back(P3D::Shader::Load(*child));
			break;
		}
		case P3D::ChunkType::Texture:
		{
			_textures.push_back(P3D::Texture::Load(*child));
			break;
		}
		default: break;
		}
	}
}

CompositeModel::CompositeModel(const ICompositeModel& provider)
{
	const auto& drawables = provider.GetDrawables();
	const auto& skeletons = provider.GetSkeletons();
	const auto& meshes = provider.GetMeshes();
	const auto& shaders = provider.GetShaders();
	const auto& textures = provider.GetTextures();

	std::map<std::string, size_t> meshNames;
	std::map<std::string, std::vector<Matrix4x4>> jointTransforms;

	for (const auto& meshP3D : meshes)
	{
		meshNames.insert({meshP3D->GetName(), _meshes.size()});
		auto mesh = std::make_unique<Mesh>(*meshP3D);
		mesh->Commit();
		_meshes.push_back(std::move(mesh));
	}

	for (const auto& skeleton : skeletons)
	{
		const auto& skeletonJoints = skeleton->GetJoints();

		std::vector<Matrix4x4> transforms;
		transforms.reserve(skeletonJoints.size());
		for (const auto& joint : skeletonJoints)
			transforms.push_back(transforms.empty() ? Matrix4x4::Identity
			                                        : transforms[joint->GetParent()] * joint->GetRestPose());

		const auto& skeletonName = skeleton->GetName();
		jointTransforms.insert({skeletonName, std::move(transforms)});
	}

	for (const auto& shader : shaders) Game::GetInstance().GetResourceManager().LoadShader(*shader);

	for (const auto& texture : textures) Game::GetInstance().GetResourceManager().LoadTexture(*texture);

	for (const auto& drawable : drawables)
	{
		const auto& propList = drawable->GetPropList();
		if (!propList)
			continue;

		const auto& props = propList->GetProps();
		if (props.empty())
			continue;

		const auto& transforms = jointTransforms[drawable->GetSkeletonName()];

		for (const auto& prop : props)
		{
			const auto& propName = prop->GetName();
			if (meshNames.find(propName) == meshNames.end())
				continue;

			const auto& transform = transforms[prop->GetSkeletonJoint()];
			_props.push_back(DrawableProp {meshNames[prop->GetName()], transform});
		}
	}
}

std::unique_ptr<CompositeModel> CompositeModel::LoadP3D(const std::string& filename)
{
	if (!FileSystem::exists(filename))
	{
		std::cout << "CompositeDrawable not found: " << filename << "\n";
		return nullptr;
	}

	std::cout << "Loading CompositeDrawable: " << filename << "\n";

	const auto p3d = P3D::P3DFile(filename);
	return std::make_unique<CompositeModel>(CompositeModel_Chunk(p3d.GetRoot()));
}

void CompositeModel::Draw(GL::ShaderProgram& shader, const Matrix4x4& viewProj, const Matrix4x4& modelMatrix, bool opaque)
{
	for (const auto& prop : _props)
	{
		shader.SetUniformValue("viewProj", viewProj * modelMatrix * prop.transform);
		_meshes[prop.meshIndex]->Draw(shader, opaque);
	}
}
} // namespace Donut
