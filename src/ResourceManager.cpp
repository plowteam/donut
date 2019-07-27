#include <ResourceManager.h>

namespace Donut
{
ResourceManager::ResourceManager()
{
	constexpr GLuint errorTextureData[] = { 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFFFF00FF };
	_errorTexture                       = std::make_unique<GL::Texture2D>(2, 2, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, errorTextureData);
}

void ResourceManager::AddTexture(const std::string& name, std::unique_ptr<GL::Texture2D> texture)
{
	_textures[name] = std::move(texture);
}

void ResourceManager::AddShader(const std::string& name, std::unique_ptr<P3D::Shader> shader)
{
	_shaders[name] = std::move(shader);
}

void ResourceManager::AddFont(const std::string& name, std::unique_ptr<Font> font)
{
	_fonts[name] = std::move(font);
}

const GL::Texture2D& ResourceManager::GetTexture(const std::string& name) const
{
	if (_textures.find(name) == _textures.end())
	{
		return *_errorTexture;
	}

	return *_textures.at(name);
}

const Font* ResourceManager::GetFont(const std::string& name) const
{
	if (_fonts.find(name) == _fonts.end())
	{
		return nullptr;
	}

	return _fonts.at(name).get();
}

const GL::Texture2D& ResourceManager::GetShaderTexture(const std::string& name) const
{
	if (_shaders.find(name) == _shaders.end())
		return *_errorTexture;

	auto const& shader = _shaders.at(name);
	auto const& texture = P3D::P3DUtil::GetShaderTexture(shader);

	if (_textures.find(texture) == _textures.end())
		return *_errorTexture;

	return *_textures.at(texture);
}

} // namespace Donut
