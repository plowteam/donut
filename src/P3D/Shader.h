#pragma once

#include <P3D/P3DChunk.h>
#include <memory>
#include <string>

namespace Donut::P3D
{

class Shader
{
  public:
	Shader(const std::string& name, const std::string& texture):
	    _name(name), _texture(texture) {}

	static std::unique_ptr<Shader> Load(const P3DChunk&);

	const std::string& GetName() const { return _name; }
	const std::string& GetTexture() const { return _texture; }

  private:
	std::string _name;
	std::string _texture;
};

} // namespace Donut::P3D
