// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include <Entity.h>
#include <fmt/format.h>

namespace Donut
{

StaticEntity::StaticEntity(const P3D::StaticEntity& entity)
{
	_name = entity.GetName();
	_mesh = std::make_unique<Mesh>(*entity.GetGeometry());
	_mesh->Commit();
}

void StaticEntity::Draw(GL::ShaderProgram& shader, bool opaque)
{
	_mesh->Draw(shader, opaque);
}

InstancedStaticEntity::InstancedStaticEntity(const P3D::Geometry& geometry, const std::vector<Matrix4x4>& transforms)
{
	_name = geometry.GetName();
	_mesh = std::make_unique<MeshInstanced>(geometry, transforms);
	_mesh->Commit();
}

void InstancedStaticEntity::Draw(GL::ShaderProgram& shader, bool opaque)
{
	_mesh->Draw(shader, opaque);
}

} // namespace Donut
