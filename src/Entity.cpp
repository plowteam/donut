#include <Entity.h>
#include <fmt/format.h>

namespace Donut
{
Texture::Texture(const P3D::Texture& texture):
    _name(texture.GetName()), _width(texture.GetWidth()), _height(texture.GetHeight()),
    _glTexture(0)
{
	// more mipmaps = more images?
	assert(texture.GetNumMipMaps() == 1);

	// image handling code: move to own class?
	auto const& image = texture.GetImage();

	// generate the opengl texture, could probs do elsewhere but who cares
	glGenTextures(1, &_glTexture);
	glBindTexture(GL_TEXTURE_2D, _glTexture);

	switch (image->GetFormat())
	{
	case 1: // PNG
	{
		auto imageData = P3D::ImageData::Decode(image->GetData());

		if (imageData.comp == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.data.data());
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData.data.data());

		break;
	}
	default:
		throw std::runtime_error("non-png texture");
	}

	// generate mipmaps :)
	glGenerateMipmap(GL_TEXTURE_2D);
}

Texture::~Texture()
{
	if (_glTexture != 0)
		glDeleteTextures(1, &_glTexture);
}

void Texture::Bind(const GLenum texture) const
{
	glActiveTexture(texture);
	glBindTexture(GL_TEXTURE_2D, _glTexture);
}

Shader::Shader(const P3D::Shader& shader):
    _name(shader.GetName())
{
	auto const& pddiName = shader.GetPddiShaderName();
	if (pddiName != "simple")
		fmt::print("shader {0}: unhandled pddi type: {1}\n", _name, pddiName);

	_isTranslucent = shader.GetIsTrans() == 1;

	for (const auto& textureParam : shader.GetTextureParams())
	{
		if (textureParam->GetKey() == "TEX")
			_textureName = textureParam->GetValue();
	}

	glGenSamplers(1, &_glSampler);

	for (const auto& param : shader.GetIntegerParams())
	{
		if (param->GetKey() == "FIMD")
		{
			switch (param->GetValue())
			{
			case 0: // NN
				glSamplerParameteri(_glSampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glSamplerParameteri(_glSampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				break;
			case 1: // Linear
				glSamplerParameteri(_glSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glSamplerParameteri(_glSampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				break;
			case 2: // NN, Mip NN
				glSamplerParameteri(_glSampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
				glSamplerParameteri(_glSampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				break;
			case 3: // Linear, Mip NN
				glSamplerParameteri(_glSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
				glSamplerParameteri(_glSampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				break;
			case 4: // Linear, Mip Linear
				glSamplerParameteri(_glSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				glSamplerParameteri(_glSampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				break;
			default:
				throw std::runtime_error("bad filter mode");
			}
		}
		else if (param->GetKey() == "UVMD")
		{
			GLint glparam = (param->GetValue() == 0) ? GL_REPEAT : GL_CLAMP_TO_EDGE;

			glSamplerParameteri(_glSampler, GL_TEXTURE_WRAP_S, glparam);
			glSamplerParameteri(_glSampler, GL_TEXTURE_WRAP_T, glparam);
		}
		else if (param->GetKey() == "2SID")
		{
			_twoSided = param->GetValue() == 1;
		}

		// ATST - alpha test
	}
}

Shader::~Shader()
{
	if (_glSampler != 0)
		glDeleteSamplers(1, &_glSampler);
}

void Shader::SetTexture(Texture* texture)
{
	_texture = texture;
}

void Shader::Bind(GLuint unit) const
{
	_texture->Bind(GL_TEXTURE0 + unit);
	glBindSampler(unit, _glSampler);

	// todo: do they even use culling at all??????????
	/*glCullFace(GL_FRONT);
	if (_twoSided)
		glDisable(GL_CULL_FACE);
	else
		glEnable(GL_CULL_FACE);*/
}

StaticEntity::StaticEntity(const P3D::StaticEntity& entity)
{
	_name = entity.GetName();
	_mesh = std::make_unique<Mesh>(*entity.GetMesh());
}

void StaticEntity::Draw(const GL::ShaderProgram& shader)
{
	_mesh->Draw();
}

} // namespace Donut
