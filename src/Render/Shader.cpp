// Copyright 2019 the donut authors. See AUTHORS.md

#include <P3D/P3D.generated.h>
#include <Render/Shader.h>
#include <fmt/format.h>
#include <iostream>

namespace Donut
{

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

	for (const auto& param : shader.GetFloatParams())
	{
		if (param->GetKey() == "CBVV")
		{
		}
		else if (param->GetKey() == "MSHP")
		{
		}
	}

	uint32_t uvmd = 0;

	for (const auto& param : shader.GetIntegerParams())
	{
		if (param->GetKey() == "FIMD")
		{
			switch (param->GetValue())
			{
			case 0: // NN
				glSamplerParameteri(_glSampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
				glSamplerParameteri(_glSampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				break;
			case 1: // Linear
				glSamplerParameteri(_glSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
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
			uvmd          = param->GetValue();
			GLint glparam = (uvmd == 0) ? GL_REPEAT : GL_CLAMP_TO_EDGE;

			glSamplerParameteri(_glSampler, GL_TEXTURE_WRAP_S, glparam);
			glSamplerParameteri(_glSampler, GL_TEXTURE_WRAP_T, glparam);
		}
		else if (param->GetKey() == "2SID")
		{
			_twoSided = param->GetValue() == 1;
		}
		else if (param->GetKey() == "ATST")
		{
			_alphaTested = param->GetValue() == 1;
		}
		else if (param->GetKey() == "BLMD")
		{
			_blendMode = (BlendMode)param->GetValue();
		}
	}

	glSamplerParameterf(_glSampler, 0x84FE, 16);
}

Shader::~Shader()
{
	if (_glSampler != 0)
		glDeleteSamplers(1, &_glSampler);
}

void Shader::SetDiffuseTexture(Texture* diffuseTexture)
{
	_diffuseTexture = diffuseTexture;
}

void Shader::Bind(GLuint unit) const
{
	_diffuseTexture->Bind(unit);
	glBindSampler(unit, _glSampler);
}

} // namespace Donut
