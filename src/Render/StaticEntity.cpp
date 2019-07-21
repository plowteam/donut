#include <Render/StaticEntity.h>

namespace Donut
{

StaticEntity::StaticEntity(const P3D::StaticEntity& entity):
    _name(entity.GetName()),
	_transform(glm::mat4(1.0f))
{
	_mesh = std::make_unique<Mesh>(entity.GetMesh());
}

StaticEntity::StaticEntity(const std::string& name, const P3D::Mesh& mesh, const glm::mat4& transform) :
	_name(name)
{
	_mesh = std::make_unique<Mesh>(mesh);
	_transform = transform;
}

void StaticEntity::Draw(const GL::ShaderProgram& shader, const ResourceManager& rm) const
{
	_mesh->Draw(shader, rm);
}

} // namespace Donut
