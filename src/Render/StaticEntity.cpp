#include <Render/StaticEntity.h>

namespace Donut
{

StaticEntity::StaticEntity(const P3D::StaticEntity& entity):
    _name(entity.GetName())
{
	_mesh = std::make_unique<Mesh>(entity.GetMesh());
}

void StaticEntity::Draw(const GL::ShaderProgram& shader, const ResourceManager& rm) const
{
	_mesh->Draw(shader, rm);
}

} // namespace Donut
