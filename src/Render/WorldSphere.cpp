// Copyright 2019 the donut authors. See AUTHORS.md

#include <Render/WorldSphere.h>

namespace Donut
{

WorldSphere::WorldSphere(const P3D::WorldSphere& worldSphere):
    _name(worldSphere.GetName())
{
	auto meshes = std::vector<std::unique_ptr<Mesh>>(worldSphere.GetMeshCount());
	auto billboards = std::vector<std::unique_ptr<BillboardBatch>>(worldSphere.GetBillboardCount());
	
	for (auto const& mesh : worldSphere.GetMeshes())
		meshes.emplace_back(std::make_unique<Mesh>(*mesh))->Commit();

	for (auto const& billboard : worldSphere.GetBillboards())
		billboards.emplace_back(std::make_unique<BillboardBatch>(*billboard));
	
	// worldSphere.GetCompositeDrawable

	/*auto const& p3dMeshes = worldSphere.GetMeshes();
	for (auto& p3dMesh : p3dMeshes)
	{
		auto mesh = std::make_unique<Mesh>(*p3dMesh);
		mesh->Commit();
		_meshes.push_back(std::move(mesh));
	}*/

	// Animation
	// Skeleton
	// OldBillboardQuadGroup
	// Mesh
	// Composite Drawable
	// Old Frame Controller
	// Multi Controller
	// Skeleton
	// Lens Flare
}

void WorldSphere::Draw(GL::ShaderProgram& shader, bool opaque) const
{
	for (auto const& mesh : _meshes)
		mesh->Draw(shader, opaque);
}

} // namespace Donut
