// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace Donut
{

namespace P3D
{
class Geometry;
class Texture;
class Sprite;
class Shader;
class Set;
} // namespace P3D

class Texture;
class Shader;
class Mesh;
class Font;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	// no copying
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(ResourceManager const&) = delete;

	void AddTexture(std::shared_ptr<Texture> texture);

	void LoadTexture(const P3D::Sprite&);
	void LoadShader(const P3D::Shader&);
	void LoadSet(const P3D::Set&);
	void LoadGeometry(const P3D::Geometry&);

	// void AddTexture(const std::string& name, std::unique_ptr<Texture> texture);
	void AddFont(const std::string& name, std::unique_ptr<Font> font);

	void ImGuiDebugWindow(bool* p_open) const;

	Shader* GetShader(const std::string& name) const;
	// Texture* GetTexture(const std::string& name) const;
	Font* GetFont(const std::string& name) const;
	Mesh* GetGeometry(const std::string& name) const;

	const std::unordered_map<std::string, std::unique_ptr<Font>>& GetFonts() const { return _fonts; }

	/*const*/ Texture& GetTexture(const std::string& name) const;

	// Returns a weak pointer to a texture with the knowledge that it might
	// be unloaded at a certain point unless locked, use this to store refs.
	std::weak_ptr<Texture> GetTextureWeakPtr(const std::string& name);

	/*const*/ Texture& GetErrorTexture() const;
	std::weak_ptr<Texture> GetErrorTextureWeakPtr();

protected:
	void createErrorTexture();

	std::shared_ptr<Texture> _errorTexture;

	// almost feel like these should be weak_ptrs owned by the individual entity stores
	// weak_ptr casts to a shared_ptr lock and frees when it's been used...
	std::unordered_map<std::string, std::shared_ptr<Texture>> _textures;

	std::unordered_map<std::string, std::weak_ptr<Texture>> _textureCache;

	std::unordered_map<std::string, std::unique_ptr<Shader>> _shaders;
	std::unordered_map<std::string, std::unique_ptr<Mesh>> _geometries;
	std::unordered_map<std::string, std::unique_ptr<Font>> _fonts;
};

} // namespace Donut
