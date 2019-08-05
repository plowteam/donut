#pragma once

// #include <Entity.h>
#include <Render/Font.h>
#include <memory>
#include <string>
#include <unordered_map>

namespace Donut
{

namespace P3D
{
class Texture;
class Shader;
}

class Texture;
class Shader;

class ResourceManager
{
  public:
	ResourceManager();

	void LoadTexture(const P3D::Texture&);
	void LoadShader(const P3D::Shader&);
	void AddFont(const std::string& name, std::unique_ptr<Font> font);

	void ImGuiDebugWindow(bool* p_open) const;

	const Shader* GetShader(const std::string& name) const;
	const Font* GetFont(const std::string& name) const;

	const std::unordered_map<std::string, std::unique_ptr<Font>>& GetFonts() const { return _fonts; }

  protected:
	// std::unique_ptr<GL::Texture2D> _errorTexture;

	std::unordered_map<std::string, std::unique_ptr<Texture>> _textures;
	std::unordered_map<std::string, std::unique_ptr<Shader>> _shaders;
	std::unordered_map<std::string, std::unique_ptr<Font>> _fonts;
};

} // namespace Donut
