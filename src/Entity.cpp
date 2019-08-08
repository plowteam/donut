// Copyright 2019 the donut authors. See AUTHORS.md

#include <Entity.h>
#include <fmt/format.h>

namespace Donut
{

StaticEntity::StaticEntity(const P3D::StaticEntity& entity)
{
	_name = entity.GetName();
	_mesh = std::make_unique<Mesh>(*entity.GetMesh());
	_mesh->Commit();
}

void StaticEntity::Draw(const GL::ShaderProgram& shader, bool opaque)
{
	_mesh->Draw(opaque);
}


InstancedStaticEntity::InstancedStaticEntity(const P3D::Mesh& mesh, const std::vector<glm::mat4>& transforms)
{
	_name = mesh.GetName();
	_mesh = std::make_unique<MeshInstanced>(mesh, transforms);
	_mesh->Commit();
}

void InstancedStaticEntity::Draw(const GL::ShaderProgram& shader, bool opaque)
{
	_mesh->Draw(opaque);
}

} // namespace Donut
