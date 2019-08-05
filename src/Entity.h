#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include <Render/Mesh.h>

namespace Donut
{
namespace GL
{
class ShaderProgram;
}

namespace P3D
{
class StaticEntity;
}


class Entity
{
  public:
	Entity() = default;
	virtual ~Entity() = default;

	virtual void Draw(const GL::ShaderProgram&) {}

	const std::string& GetName() const { return _name; }
	virtual const std::string GetClassName() const { return "Entity"; }

  protected:
	std::string _name;
};

class StaticEntity: public Entity
{
  public:
	StaticEntity(const P3D::StaticEntity&);

	void Draw(const GL::ShaderProgram&) override;

	const std::string GetClassName() const override { return "StaticEntity"; }

  protected:
	std::unique_ptr<Mesh> _mesh;
};

// parent off loadobject
class Texture
{
public:
	Texture(const P3D::Texture&);
	~Texture();

	void Bind(GLenum texture) const;
	GLuint GetHandle() const { return _glTexture; }

protected:
	std::string _name;
	uint32_t _width;
	uint32_t _height;

	GLuint _glTexture;
};

class Shader
{
  public:
	Shader(const P3D::Shader&);
	~Shader();

	void Bind(GLuint unit) const;

	const std::string& GetTextureName() const { return _textureName; }
	void SetTexture(Texture* texture);

  protected:
	std::string _name;
	std::string _textureName;
	Texture* _texture;

	GLuint _glSampler;
	bool _twoSided;
};

} // namespace Donut
