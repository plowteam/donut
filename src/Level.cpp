#include <Level.h>
#include <P3D/StaticEntity.h>
#include <P3D/Texture.h>
#include <P3D/P3DFile.h>

#include <glm/gtx/transform.hpp>
#include <iostream>

namespace Donut
{

std::string lvlVertexShader = R"glsl(
	#version 150 core

	in vec3 position;
	in vec2 uv;

	out vec2 texCoord;

	uniform mat4 viewProj;

	void main()
	{
		texCoord = uv;
		gl_Position = viewProj * vec4(position, 1.0);
	}
)glsl";

std::string lvlFragmentShader = R"glsl(
	#version 150 core

	uniform sampler2D diffuseTex;

	in vec2 texCoord;
	out vec4 outColor;

	void main()
	{
		vec3 diffuseColor = texture2D(diffuseTex, texCoord).rgb;

        outColor = vec4(diffuseColor, 1.0);
	}
)glsl";

Level::Level()
{
	_worldShader = std::make_unique<GL::ShaderProgram>(lvlVertexShader, lvlFragmentShader);
	_resourceManager = std::make_unique<ResourceManager>();
}

void Level::LoadP3D(const std::string& filename)
{
	if (!std::filesystem::exists(filename))
	{
		std::cout << "Level not found: " << filename << "\n";
		return;
	}

	std::cout << "Loading level: " << filename << "\n";

	auto p3d = P3D::P3DFile(filename);

	const auto& root = p3d.GetRoot();
	for (const auto& chunk : root.GetChildren())
	{
		switch (chunk->GetType())
		{
		case P3D::ChunkType::Shader:
		{
			auto shader                 = P3D::Shader::Load(*chunk);
			const std::string shader_name = shader->GetName();
			_resourceManager->AddShader(shader_name, std::move(shader));
			break;
		}
		case P3D::ChunkType::Texture:
		{
			auto texture = P3D::Texture::Load(*chunk);
			auto texdata = texture->GetData();
			auto tex2d   = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, texdata.data.data());
			_resourceManager->AddTexture(texture->GetName(), std::move(tex2d));
			
			break;
		}
		case P3D::ChunkType::StaticEntity:
		{
			auto ent = P3D::StaticEntity::Load(*chunk);
			// std::cout << "Static Entity: " << ent->GetName() << "\n";

			auto model = std::make_unique<StaticModel>(std::move(ent));
			_models.push_back(std::move(model));
			break;
		}
		default: break;
		}
	}
}

void Level::Draw(const ResourceManager& rm, glm::mat4& viewProj)
{
	_worldShader->Bind();
	_worldShader->SetUniformValue("viewProj", viewProj);

	rm.GetTexture("errorlol").Bind(0);
	for (const auto& model : _models)
	{
		model->Draw(*_worldShader, *_resourceManager);
	}
}

} // namespace Donut
