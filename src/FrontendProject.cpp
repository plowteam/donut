// Copyright 2019 the donut authors. See AUTHORS.md

#include <FrontendProject.h>
#include <P3D/P3DFile.h>
#include <P3D/p3d.generated.h>
#include <Render/OpenGL/Texture2D.h>
#include <Game.h>
#include <ResourceManager.h>
#include <Entity.h>
#include <iostream>
#include <fmt/format.h>

namespace Donut
{
	void FrontendProject::LoadP3D(const std::string& filename)
	{
		if (!std::filesystem::exists(filename))
		{
			std::cout << "Frontend Project not found: " << filename << "\n";
			return;
		}

		std::cout << "Loading Frontend Project: " << filename << "\n";

		const auto p3d = P3D::P3DFile(filename);
		const auto& root = p3d.GetRoot();
		for (const auto& chunk : root.GetChildren())
		{
			switch (chunk->GetType())
			{
				case P3D::ChunkType::FrontendProject:
				{
					auto project = P3D::FrontendProject::Load(*chunk);
					break;
				}
				case P3D::ChunkType::Sprite:
				{
					auto sprite = P3D::Sprite::Load(*chunk);
					Game::GetInstance().GetResourceManager().LoadTexture(*sprite);

					break;
				}
				case P3D::ChunkType::TextureFont:
				{
					auto font = P3D::TextureFont::Load(*chunk);
					break;
				}
			}
		}
	}

	void FrontendProject::Draw(const glm::mat4& proj)
	{
	}
}
