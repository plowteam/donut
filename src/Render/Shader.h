#pragma once
#include "glad/glad.h"

#include <memory>
#include <string>
#include <Render/Texture.h>
#include <unordered_map>

namespace Donut
{

// forward declare
namespace P3D
{
class Shader;
}


class Shader
{
  public:
	Shader(const P3D::Shader&);
	~Shader();

	// void SetShaderEffect(const std::string& effect);
	// std::string GetShaderEffect() const { return _shaderEffect; }

	void SetDiffuseTexture(TexturePtr diffuseTexture);
	const TexturePtr& GetDiffuseTexture() const { return _diffuseTexture; }

	// used to SetDiffuseTexture, won't be needed if Shader is constructed independent of P3D::Shader
	std::string GetDiffuseTextureName() const { return _textureName; }

	// Diffuse Color
	// 

	void Bind(GLuint unit) const;

	bool HasLighting() const { return _hasLighting; }
	bool IsAlphaTested() const { return _alphaTested; }
	bool IsTwoSided() const { return _twoSided; }

	bool IsTranslucent() const { return _isTranslucent; }

  protected:
	std::string _name;
	std::string _textureName;

	std::string _shaderEffect;

	TexturePtr _diffuseTexture;
	TexturePtr _envmapTexture;

	GLuint _glSampler;

	bool _isTranslucent;

	bool _hasLighting;
	bool _alphaTested;
	bool _twoSided;
};

using ShaderPtr = std::shared_ptr<Shader>;

} // namespace Donut
