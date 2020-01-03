// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Vector3Int.h"
#include "Render/OpenGL/IndexBuffer.h"
#include "Render/OpenGL/TextureBuffer.h"
#include "Render/OpenGL/VertexBinding.h"
#include "Render/OpenGL/VertexBuffer.h"
#include "Render/SkinAnimation.h"
#include "ResourceManager.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace Donut
{

namespace P3D
{
class Animation;
class PolySkin;
class Shader;
class Skeleton;
class Texture;
} // namespace P3D

// SkinModel is a redrawable PolySkin model, animations are seperate but bound to shader.
class SkinModel
{
	struct Vertex
	{
		Vector3 pos;
		Vector3 normal;
		Vector2 uv;
		Vector3 boneWeights;
		Vector3Int boneIndices;

		Vertex(Vector3 pos, Vector3 normal, Vector2 uv, Vector3 boneWeights, Vector3Int boneIndices)
		    : pos(pos), normal(normal), uv(uv), boneWeights(boneWeights), boneIndices(boneIndices)
		{
		}
	};

	struct PrimGroup
	{
		GLenum mode;
		std::string shaderName;
		std::size_t indicesOffset;
		std::size_t indicesCount;

		PrimGroup(GLenum mode, std::string shaderName, std::size_t indicesOffset, std::size_t indicesCount)
		    : mode(mode), shaderName(std::move(shaderName)), indicesOffset(indicesOffset), indicesCount(indicesCount)
		{
		}
	};

public:
	SkinModel() = default;

	// Load methods
	void LoadPolySkin(const P3D::PolySkin&);

	// Update / Draw methods
	// void UpdateAnimation(SkinAnimation& anim, double time);
	void Draw();

private:
	std::unique_ptr<GL::VertexBinding> _vertexBinding;
	std::unique_ptr<GL::VertexBuffer> _vertexBuffer;
	std::unique_ptr<GL::IndexBuffer> _indexBuffer;
	std::vector<PrimGroup> _primGroups;
};

} // namespace Donut
