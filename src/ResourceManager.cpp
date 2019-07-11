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

const GL::Texture2D& ResourceManager::GetTexture(const std::string& name) const
{
	if (_textures.find(name) == _textures.end())
	{
		return *_errorTexture.get();
	}

	return *_textures.at(name);
}

} // namespace Donut
