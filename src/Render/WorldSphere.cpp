#include <Render/WorldSphere.h>

namespace Donut
{

WorldSphere::WorldSphere(const P3D::WorldSphere& worldSphere):
    _name(worldSphere.GetName())
{
	auto const& p3dMeshes = worldSphere.GetMeshes();
	for (auto& p3dMesh : p3dMeshes)
		_meshes.push_back(std::make_unique<Mesh>(*p3dMesh));
}

void WorldSphere::Draw(const GL::ShaderProgram& shader) const
{
	for (auto const& mesh : _meshes)
		mesh->Draw();
}

} // namespace Donut
