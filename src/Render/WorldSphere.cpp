// Copyright 2019 the donut authors. See AUTHORS.md

#include <Render/WorldSphere.h>

namespace Donut
{

WorldSphere::WorldSphere(const P3D::WorldSphere& worldSphere):
    _name(worldSphere.GetName())
{
	auto const& p3dMeshes = worldSphere.GetMeshes();
	for (auto& p3dMesh : p3dMeshes)
	{
		auto mesh = std::make_unique<Mesh>(*p3dMesh);
		mesh->Commit();
		_meshes.push_back(std::move(mesh));
	}
}

void WorldSphere::Draw(GL::ShaderProgram& shader, bool opaque) const
{
	for (auto const& mesh : _meshes)
		mesh->Draw(shader, opaque);
}

} // namespace Donut
