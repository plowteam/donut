// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace Donut
{

class Texture;
class Shader;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	// no copying
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(ResourceManager const&) = delete;

	void AddTexture(std::shared_ptr<Texture> texture);

	void ImGuiDebugWindow(bool* p_open) const;

	Shader* GetShader(const std::string& name) const;
	// Texture* GetTexture(const std::string& name) const;

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
};

} // namespace Donut
