// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <Render/OpenGL/IndexBuffer.h>
#include <Render/OpenGL/ShaderProgram.h>
#include <Render/OpenGL/VertexBuffer.h>
#include <Render/OpenGL/VertexBinding.h>
#include <Render/SkinAnimation.h>
#include <P3D/p3d.generated.h>
#include <ResourceManager.h>
#include <glm/glm.hpp>
#include <string>

namespace Donut
{

class Mesh
{
public:

	Mesh(const P3D::Mesh& mesh);

	void Commit();
	void Draw(GL::ShaderProgram&, bool opaque);

protected:

	struct PrimGroup
	{
		std::string shaderName;
		GLenum type;
		std::size_t indicesOffset;
		std::size_t indicesCount;
		Shader* cacheShader;
	};

	struct Vertex
	{
		glm::vec3 pos;
		glm::vec2 uv;
		glm::vec4 co0lor;
	};

	void CreateMeshBuffers(const P3D::Mesh& mesh);
	virtual void CreateVertexBinding();

	virtual void DrawPrimGroup(const PrimGroup& primGroup);

	std::string _name;
	std::vector<PrimGroup> _primGroups;

	std::shared_ptr<GL::VertexBuffer> _vertexBuffer;
	std::shared_ptr<GL::IndexBuffer> _indexBuffer;
	std::shared_ptr<GL::VertexBinding> _vertexBinding;

	glm::vec3 _boundingBoxMin;
	glm::vec3 _boundingBoxMax;
};

class MeshInstanced : public Mesh
{
public:

	MeshInstanced(const P3D::Mesh& mesh, const std::vector<glm::mat4>& transforms);

protected:

	virtual void CreateVertexBinding() override;

	virtual void DrawPrimGroup(const PrimGroup& primGroup) override;

	std::vector<glm::mat4> _transforms;
	std::shared_ptr<GL::VertexBuffer> _instanceBuffer;
};

} // namespace Donut
