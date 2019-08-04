#pragma once

#include "Render/Mesh.h"

#include <memory>
#include <string>

namespace Donut
{
namespace GL
{
class ShaderProgram;
}

class ResourceManager;

namespace P3D
{
class StaticEntity;
}

class Entity
{
  public:
	virtual ~Entity() {}

	virtual void Draw(const GL::ShaderProgram&, const ResourceManager&) {}

	const std::string& GetName() const { return _name; }
	virtual const std::string GetClassName() const { return "Entity"; }

  protected:
	Entity() = default;
	std::string _name;
};

class StaticEntity: public Entity
{
  public:
	StaticEntity(const P3D::StaticEntity&);

	void Draw(const GL::ShaderProgram&, const ResourceManager&) override;

	const std::string GetClassName() const override { return "StaticEntity"; }

  protected:
	std::unique_ptr<Mesh> _mesh;
};

// parent off loadobject
class Texture
{
public:
	Texture(const P3D::Texture&);

protected:
	std::string _name;
	uint32_t _width;
	uint32_t _height;

	GLuint _glTexture;
};

} // namespace Donut
