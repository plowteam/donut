#pragma once

#include <P3D/Shader.h>
#include <GL/Texture2D.h>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace Donut
{

class ResourceManager
{
  public:
	ResourceManager();

	void AddTexture(const std::string& name, std::unique_ptr<GL::Texture2D> texture);
	void AddShader(const std::string& name, std::unique_ptr<P3D::Shader> shader);

	const GL::Texture2D& GetTexture(const std::string& name) const;
	const GL::Texture2D& GetShaderTexture(const std::string& name) const;
	const std::map<std::string, std::unique_ptr<GL::Texture2D>>& GetTextures() const { return _textures; }
	const std::map<std::string, std::unique_ptr<P3D::Shader>>& GetShaders() const { return _shaders; }

  protected:
	std::unique_ptr<GL::Texture2D> _errorTexture;
	std::map<std::string, std::unique_ptr<GL::Texture2D>> _textures;
	std::map<std::string, std::unique_ptr<P3D::Shader>> _shaders;
};

} // namespace Donut
