// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

// #include <Entity.h>
#include <Render/Font.h>
#include <Render/Shader.h>
#include <memory>
#include <string>
#include <unordered_map>

namespace Donut
{

namespace P3D
{
class Texture;
class Sprite;
class Shader;
class Set;
}

class Texture;
// class Shader;

class ResourceManager
{
  public:
	ResourceManager();

	void LoadTexture(const P3D::Texture&);
	void LoadTexture(const P3D::Sprite&);
	void LoadShader(const P3D::Shader&);
	void LoadSet(const P3D::Set&);

	void AddTexture(const std::string& name, std::unique_ptr<Texture> texture);
	void AddFont(const std::string& name, std::unique_ptr<Font> font);

	void ImGuiDebugWindow(bool* p_open) const;

	ShaderPtr GetShader(const std::string& name) const;
	const Font* GetFont(const std::string& name) const;

	const std::unordered_map<std::string, std::unique_ptr<Font>>& GetFonts() const { return _fonts; }

  protected:
	// std::unique_ptr<GL::Texture2D> _errorTexture;

	std::unordered_map<std::string, std::shared_ptr<Texture>> _textures;
	std::unordered_map<std::string, std::shared_ptr<Shader>> _shaders;
	std::unordered_map<std::string, std::unique_ptr<Font>> _fonts;
};

} // namespace Donut
