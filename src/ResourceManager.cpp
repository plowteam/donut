// Copyright 2019 the donut authors. See AUTHORS.md

#include <Entity.h>
#include <ResourceManager.h>

#include <imgui.h>
#include <fmt/format.h>

namespace Donut
{

ResourceManager::ResourceManager()
{
	// constexpr GLuint errorTextureData[] = { 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFFFF00FF };
	// _errorTexture                       = std::make_unique<GL::Texture2D>(2, 2, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, errorTextureData);
}

void ResourceManager::LoadTexture(const P3D::Texture& texture)
{
	_textures[texture.GetName()] = std::make_unique<Texture>(texture);
}

void ResourceManager::LoadShader(const P3D::Shader& shader)
{
	_shaders[shader.GetName()] = std::make_unique<Shader>(shader);
}

void ResourceManager::LoadSet(const P3D::Set& set)
{
	std::srand(std::time(0));
	int idx = std::rand() % set.GetTextures().size();
	_textures[set.GetName()] = std::make_unique<Texture>(*set.GetTextures().at(idx));
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

	ImGui::Text("Textures: %d", _textures.size());
	ImGui::SameLine();
	ImGui::Text("Shaders: %d", _shaders.size());
	ImGui::SameLine();
	ImGui::Text("Fonts: %d", _fonts.size());

	ImGui::BeginTabBar("rmtabs");

	if (ImGui::BeginTabItem("Textures"))
	{
		const ImVec2 windowSize = ImGui::GetWindowSize();
		int perLine       = static_cast<int>(windowSize.x) / 72;
		if (perLine == 0)
			perLine = 1;

		int i = 0;
		for (auto const& [name, texture] : _textures)
		{
			ImGui::Image(reinterpret_cast<ImTextureID>(texture->GetHandle()), ImVec2(64, 64));
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip(name.c_str());

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
	const std::string texName = shader->GetTextureName();
	if (_textures.find(texName) != _textures.end())
		shader->SetTexture(_textures.at(texName).get());
	else
	{
		fmt::print("could not find texture {1} for shader {0}\n", name, texName);
		shader->SetTexture(_textures.begin()->second.get()); // todo: set an error texture	
	}

	return shader.get();
}

const Font* ResourceManager::GetFont(const std::string& name) const
{
	if (_fonts.find(name) == _fonts.end())
	{
		return nullptr;
	}

	return _fonts.at(name).get();
}

} // namespace Donut
