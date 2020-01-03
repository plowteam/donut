// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Fwd.h"
#include "P3D/P3D.generated.h"
#include "Render/OpenGL/IndexBuffer.h"
#include "Render/OpenGL/ShaderProgram.h"
#include "Render/OpenGL/VertexBinding.h"
#include "Render/OpenGL/VertexBuffer.h"
#include "Render/SkinAnimation.h"

#include <string>

namespace Donut
{

class Shader;

class Mesh
{
public:
	Mesh(const P3D::Geometry& geometry);

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
		Vector3 pos;
		Vector2 uv;
		Vector4 co0lor;
	};

	void CreateMeshBuffers(const P3D::Geometry& geometry);
	virtual void CreateVertexBinding();

	virtual void DrawPrimGroup(const PrimGroup& primGroup);

	std::string _name;
	std::vector<PrimGroup> _primGroups;

	std::shared_ptr<GL::VertexBuffer> _vertexBuffer;
	std::shared_ptr<GL::IndexBuffer> _indexBuffer;
	std::shared_ptr<GL::VertexBinding> _vertexBinding;

	Vector3 _boundingBoxMin;
	Vector3 _boundingBoxMax;
};

class MeshInstanced: public Mesh
{
public:
	MeshInstanced(const P3D::Geometry& geometry, const std::vector<Matrix4x4>& transforms);

protected:
	virtual void CreateVertexBinding() override;

	virtual void DrawPrimGroup(const PrimGroup& primGroup) override;

	std::vector<Matrix4x4> _transforms;
	std::shared_ptr<GL::VertexBuffer> _instanceBuffer;
};

} // namespace Donut
