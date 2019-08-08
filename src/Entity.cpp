// Copyright 2019 the donut authors. See AUTHORS.md

#include <Entity.h>
#include <fmt/format.h>

namespace Donut
{

StaticEntity::StaticEntity(const P3D::StaticEntity& entity)
{
	_name = entity.GetName();
	_mesh = std::make_unique<Mesh>(*entity.GetMesh());
}

void StaticEntity::Draw(const GL::ShaderProgram& shader, bool opaque)
{
	_mesh->Draw(opaque);
}

} // namespace Donut
