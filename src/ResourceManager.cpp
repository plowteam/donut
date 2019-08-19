// Copyright 2019 the donut authors. See AUTHORS.md

#include <ResourceManager.h>
#include <P3D/P3D.generated.h>

#include <Render/Font.h>
#include <Render/Shader.h>
#include <Render/Texture.h>
#include <Render/Mesh.h>

#include <fmt/format.h>
#include <imgui.h>
#include <chrono>

namespace Donut
{

ResourceManager::ResourceManager() = default;
ResourceManager::~ResourceManager() = default;

void ResourceManager::LoadTexture(const P3D::Texture& texture)
{
	if (_textures.find(texture.GetName()) != _textures.end())
		fmt::print("Texture {0} already loaded\n", texture.GetName());

	_textures[texture.GetName()] = std::make_unique<Texture>(texture);
}

void ResourceManager::LoadTexture(const P3D::Sprite& sprite)
{
	if (_textures.find(sprite.GetName()) != _textures.end())
		fmt::print("Sprite {0} already loaded\n", sprite.GetName());

	_textures[sprite.GetName()] = std::make_unique<Texture>(sprite);
}

void ResourceManager::LoadShader(const P3D::Shader& shader)
{
	if (_shaders.find(shader.GetName()) != _shaders.end())
		fmt::print("Shader {0} already loaded\n", shader.GetName());

	_shaders[shader.GetName()] = std::make_unique<Shader>(shader);
}

void ResourceManager::LoadSet(const P3D::Set& set)
{
	if (_textures.find(set.GetName()) != _textures.end())
		fmt::print("Set {0} already loaded\n", set.GetName());

	std::srand((uint32_t)std::time(0));
	int idx                  = std::rand() % set.GetTextures().size();
	_textures[set.GetName()] = std::make_unique<Texture>(*set.GetTextures().at(idx));
}

void ResourceManager::LoadGeometry(const P3D::Geometry& geo)
{
	if (_geometries.find(geo.GetName()) != _geometries.end())
		fmt::print("Geometry {0} already loaded\n", geo.GetName());

	_geometries[geo.GetName()] = std::make_unique<Mesh>(geo);
}

void ResourceManager::AddTexture(const std::string& name, std::unique_ptr<Texture> texture)
{
	_textures[name] = std::move(texture);
}

void ResourceManager::AddFont(const std::string& name, std::unique_ptr<Font> font)
{
	_fonts[name] = std::move(font);
}

void ResourceManager::ImGuiDebugWindow(bool* p_open) const
{
	ImGui::SetNextWindowSize(ImVec2(330, 400), ImGuiSetCond_Once);
	if (!ImGui::Begin("Resource Manager", p_open))
	{
		ImGui::End();
		return;
	}

	ImGui::Text("Textures: %zu", _textures.size());
	ImGui::SameLine();
	ImGui::Text("Shaders: %zu", _shaders.size());
	ImGui::SameLine();
	ImGui::Text("Fonts: %zu", _fonts.size());

	ImGui::BeginTabBar("rmtabs");

	if (ImGui::BeginTabItem("Textures"))
	{
		const ImVec2 windowSize = ImGui::GetWindowSize();
		int perLine             = static_cast<int>(windowSize.x) / 72;
		if (perLine == 0)
			perLine = 1;

		int i = 0;
		for (auto const& [name, texture] : _textures)
		{
			ImGui::Image((ImTextureID)(intptr_t)texture->GetOpenGLHandle(), ImVec2((float)texture->GetWidth(), (float)texture->GetHeight()));
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("%s", name.c_str());

			if (++i % perLine != 0)
				ImGui::SameLine();
		}

		ImGui::EndTabItem();
	}

	ImGui::EndTabBar();

	ImGui::End();
}

/*
 * Searches for the shader in the map, you should cache the result to avoid unnecessary lookups
 */
Shader* ResourceManager::GetShader(const std::string& name) const
{
	if (_shaders.find(name) == _shaders.end())
	{
		fmt::print("could not find shader {0}\n", name);
		return nullptr; // todo: return an error shader
	}

	auto const& shader = _shaders.at(name);

	// todo: check if a texture is set/valid before setting texture again
	const std::string texName = shader->GetDiffuseTextureName();
	if (_textures.find(texName) != _textures.end())
		shader->SetDiffuseTexture(_textures.at(texName).get());
	else
	{
		fmt::print("could not find texture {1} for shader {0}\n", name, texName);
		shader->SetDiffuseTexture(_textures.begin()->second.get()); // todo: set an error texture
	}

	return shader.get();
}

Texture* ResourceManager::GetTexture(const std::string& name) const
{
	// todo: return missing texture
	if (_textures.find(name) == _textures.end())
		return nullptr;

	return _textures.at(name).get();
}

Mesh* ResourceManager::GetGeometry(const std::string& name) const
{
	if (_geometries.find(name) == _geometries.end())
		return nullptr;

	return _geometries.at(name).get();
}

Font* ResourceManager::GetFont(const std::string& name) const
{
	if (_fonts.find(name) == _fonts.end())
		return nullptr;

	return _fonts.at(name).get();
}

} // namespace Donut
