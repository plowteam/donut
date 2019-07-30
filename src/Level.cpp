#include <Level.h>
#include <P3D/P3DFile.h>
#include <P3D/p3d.generated.h>
#include <Physics/WorldPhysics.h>
#include <Render/OpenGL/ShaderProgram.h>
#include <Render/StaticEntity.h>
#include <ResourceManager.h>
#include <array>
#include <iostream>

namespace Donut
{

std::string lvlVertexShader = R"glsl(
	#version 150 core

	in vec3 position;
	in vec2 uv;
	in vec4 color;

	out vec2 texCoord;
	out vec4 vertColor;

	uniform mat4 viewProj;

	void main()
	{
		texCoord = uv;
		vertColor = color;
		gl_Position = viewProj * vec4(position, 1.0);
	}
)glsl";

std::string lvlFragmentShader = R"glsl(
	#version 150 core

	uniform sampler2D diffuseTex;

	in vec2 texCoord;
	in vec4 vertColor;

	out vec4 outColor;

	void main()
	{
		vec4 diffuseColor = texture2D(diffuseTex, texCoord);
		if (diffuseColor.a == 0.0)
			discard;

        outColor = vec4(diffuseColor.rgb * vertColor.rgb, diffuseColor.a);
	}
)glsl";

Level::Level(WorldPhysics* worldPhysics)
{
	_worldShader     = std::make_unique<GL::ShaderProgram>(lvlVertexShader, lvlFragmentShader);
	_resourceManager = std::make_unique<ResourceManager>();
	_worldPhysics    = worldPhysics;

	std::array<std::string, 7> carFiles {
		"art/cars/mrplo_v.p3d",
		"art/cars/carhom_v.p3d",
		"art/cars/krust_v.p3d",
		"art/cars/cDuff.p3d",
		"art/cars/bart_v.p3d",
		"art/cars/snake_v.p3d",
		"art/cars/wiggu_v.p3d",
	};

	float offset = 0.0f;
	for (const auto& carFile : carFiles)
	{
		if (auto car = CompositeModel::LoadP3D(carFile, _resourceManager))
		{
			auto transform = glm::translate(glm::mat4(1.0f), glm::vec3(240 + offset, 4.6f, -160));
			car->SetTransform(transform);
			_compositeModels.push_back(std::move(car));
			offset += 3.0f;
		}
	}
}

void Level::LoadP3D(const std::string& filename)
{
	if (!std::filesystem::exists(filename))
	{
		std::cout << "Level not found: " << filename << "\n";
		return;
	}

	std::cout << "Loading level: " << filename << "\n";

	std::vector<std::unique_ptr<P3D::Locator2>> locators;

	const auto p3d = P3D::P3DFile(filename);

	const auto& root = p3d.GetRoot();
	for (const auto& chunk : root.GetChildren())
	{
		switch (chunk->GetType())
		{
		case P3D::ChunkType::Shader:
		{
			auto shader                   = P3D::Shader::Load(*chunk);
			const std::string shader_name = shader->GetName();
			_resourceManager->AddShader(shader_name, std::make_unique<Shader>(*shader));
			break;
		}
		case P3D::ChunkType::Texture:
		{
			auto texture = P3D::Texture::Load(*chunk);
			auto texdata = P3D::ImageData::Decode(texture->GetImage()->GetData());

			std::unique_ptr<GL::Texture2D> tex;
			if (texdata.comp == 4)
				tex = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, texdata.data.data());
			else
				tex = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, texdata.data.data());

			_resourceManager->AddTexture(texture->GetName(), std::move(tex));

			break;
		}
		case P3D::ChunkType::StaticEntity:
		{
			const auto& ent = P3D::StaticEntity::Load(*chunk);
			auto model      = std::make_unique<StaticEntity>(*ent);

			_staticEntities.push_back(std::move(model));
			break;
		}
		case P3D::ChunkType::StaticPhysics:
		{
			const auto& ent = P3D::StaticPhysics::Load(*chunk);
			// std::cout << "StaticPhys: " << ent->GetName() << "\n";
			// std::cout << "\tCollisionObject: " << ent->GetCollisionObject()->GetName() << "\n";

			auto const& volume = ent->GetCollisionObject()->GetVolume();
			if (volume != nullptr)
				_worldPhysics->AddCollisionVolume(*volume);

			break;
		}
		case P3D::ChunkType::InstancedStaticPhysics:
		{
			const auto& staticPhys = P3D::InstancedStaticPhysics::Load(*chunk);
			std::vector<P3D::SceneGraphDrawable*> drawables;
			std::vector<glm::mat4> transforms;
			P3D::P3DUtil::GetDrawables(staticPhys->GetInstanceList(), drawables, transforms);

			const auto& meshes = staticPhys->GetMeshes();
			std::map<std::string, size_t> meshesNameIndex;
			for (const auto& mesh : meshes)
			{
				meshesNameIndex.insert({ mesh->GetName(), meshesNameIndex.size() });
			}

			for (size_t i = 0; i < drawables.size(); ++i)
			{
				const auto& drawable  = drawables.at(i);
				const auto& transform = transforms.at(i);

				const auto& meshName = drawable->GetName();
				const auto& mesh     = meshes.at(meshesNameIndex.at(meshName));

				auto model = std::make_unique<StaticEntity>(meshName, *mesh, transform);
				_staticEntities.push_back(std::move(model));
			}

			break;
		}
		case P3D::ChunkType::DynamicPhysics:
		{
			const auto& dynaPhys = P3D::DynamicPhysics::Load(*chunk);
			std::vector<P3D::SceneGraphDrawable*> drawables;
			std::vector<glm::mat4> transforms;
			P3D::P3DUtil::GetDrawables(dynaPhys->GetInstanceList(), drawables, transforms);

			const auto& meshes = dynaPhys->GetMeshes();
			std::map<std::string, size_t> meshesNameIndex;
			for (const auto& mesh : meshes)
			{
				meshesNameIndex.insert({ mesh->GetName(), meshesNameIndex.size() });
			}

			for (size_t i = 0; i < drawables.size(); ++i)
			{
				const auto& drawable  = drawables.at(i);
				const auto& transform = transforms.at(i);

				const auto& meshName = drawable->GetName();
				const auto& mesh     = meshes.at(meshesNameIndex.at(meshName));

				auto model = std::make_unique<StaticEntity>(meshName, *mesh, transform);
				_staticEntities.push_back(std::move(model));
			}

			break;
		}
		case P3D::ChunkType::AnimDynamicPhysics:
		{
			const auto& dynaPhys = P3D::AnimDynamicPhysics::Load(*chunk);
			std::vector<P3D::SceneGraphDrawable*> drawables;
			std::vector<glm::mat4> transforms;
			P3D::P3DUtil::GetDrawables(dynaPhys->GetInstanceList(), drawables, transforms);

			const auto& animObjectWrapper = dynaPhys->GetAnimObjectWrapper();

			for (size_t i = 0; i < drawables.size(); ++i)
			{
				const auto& drawable  = drawables.at(i);
				const auto& transform = transforms.at(i);

				auto compositeModel = std::make_unique<CompositeModel>(CompositeModel_AnimObjectWrapper(*animObjectWrapper), _resourceManager);
				compositeModel->SetTransform(transform);
				_compositeModels.push_back(std::move(compositeModel));
			}

			break;
		}
		case P3D::ChunkType::Intersect:
		{
			auto intersect = P3D::Intersect::Load(*chunk);
			_worldPhysics->AddIntersect(*intersect);

			break;
		}
		case P3D::ChunkType::WorldSphere:
		{
			auto worldSphere = P3D::WorldSphere::Load(*chunk);
			std::cout << "world sphere: " << worldSphere->GetName() << " has " << worldSphere->GetMeshes().size() << " meshes\n";
			_worldSphere = std::make_unique<WorldSphere>(*worldSphere);
			break;
		}
		case P3D::ChunkType::Locator2:
		{
			locators.push_back(std::move(P3D::Locator2::Load(*chunk)));
			break;
		}
		case P3D::ChunkType::FenceWrapper:
		{
			auto const& fence = P3D::FenceWrapper::Load(*chunk);
			_worldPhysics->AddP3DFence(*fence->GetFence());
		}
		default: break;
		}
	}
}

void Level::Draw(const ResourceManager& rm, glm::mat4& viewProj)
{
	_worldShader->Bind();
	_worldShader->SetUniformValue("viewProj", viewProj);

	if (_worldSphere != nullptr)
		_worldSphere->Draw(*_worldShader, *_resourceManager);

	for (const auto& ent : _staticEntities)
	{
		_worldShader->SetUniformValue("viewProj", viewProj * ent->GetTransform());
		ent->Draw(*_worldShader, *_resourceManager);
	}

	for (const auto& compositeModel : _compositeModels)
	{
		compositeModel->Draw(*_worldShader, viewProj, compositeModel->GetTransform());
	}
}

} // namespace Donut
