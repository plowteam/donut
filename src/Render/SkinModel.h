// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <Render/OpenGL/IndexBuffer.h>
#include <Render/OpenGL/TextureBuffer.h>
#include <Render/OpenGL/VertexBinding.h>
#include <Render/OpenGL/VertexBuffer.h>
#include <Render/SkinAnimation.h>
#include <ResourceManager.h>
#include <glm/glm.hpp>
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
		glm::vec3 pos;
		glm::vec3 normal;
		glm::vec2 uv;
		glm::vec3 boneWeights;
		glm::ivec3 boneIndices;

		Vertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 uv, glm::vec3 boneWeights, glm::ivec3 boneIndices):
		    pos(pos), normal(normal), uv(uv), boneWeights(boneWeights), boneIndices(boneIndices)
		{
		}
	};

	struct PrimGroup
	{
		GLenum mode;
		std::string shaderName;
		std::size_t indicesOffset;
		std::size_t indicesCount;

		PrimGroup(GLenum mode, std::string shaderName, std::size_t indicesOffset, std::size_t indicesCount):
		    mode(mode), shaderName(std::move(shaderName)), indicesOffset(indicesOffset), indicesCount(indicesCount)
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
