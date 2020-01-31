// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Core/FileSystem.h"
#include <Entity.h>
#include <FrontendProject.h>
#include <Game.h>
#include <P3D/P3D.generated.h>
#include <P3D/P3DFile.h>
#include <Render/OpenGL/GLTexture2D.h>
#include "Pure3D/Texture.h"
#include <ResourceManager.h>
#include <fmt/format.h>
#include <iostream>

namespace Donut
{
enum class Alignment
{
	Left,
	Right,
	Top,
	Bottom,
	Center
};

FrontendProject::FrontendProject()
{
	glGenSamplers(1, &_sampler);
	glSamplerParameteri(_sampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glSamplerParameteri(_sampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

FrontendProject::~FrontendProject()
{
	if (_sampler != 0)
	{
		glDeleteSamplers(1, &_sampler);
	}
}

void FrontendProject::AddMultiSprite(const P3D::FrontendMultiSprite& multiSprite, int32_t resX, int32_t resY)
{
	auto texture = Game::GetInstance().GetResourceManager().GetTexture(multiSprite.GetImageNames()[0] + ".png");
	auto dimX = (int32_t)multiSprite.GetDimensionX();
	auto dimY = (int32_t)multiSprite.GetDimensionY();
	Alignment alignX = (Alignment)multiSprite.GetAlignX();
	Alignment alignY = (Alignment)multiSprite.GetAlignY();

	int32_t x = multiSprite.GetPositionX();
	int32_t y = resY - multiSprite.GetPositionY();
	int32_t w = texture->GetWidth();
	int32_t h = texture->GetHeight();

	if (alignX == Alignment::Right)
	{
		x += dimX - w;
	}
	if (alignX == Alignment::Center)
	{
		x += ((dimX - w) * 0.5f);
		if (dimX > w && alignY != Alignment::Center)
		{
			x -= (dimX * 0.5f) - w;
			w = dimX - w;
		}
	}

	if (alignY == Alignment::Top)
	{
		y -= dimY;
	}
	else if (alignY == Alignment::Bottom)
	{
		y -= h;
	}
	else if (alignY == Alignment::Center)
	{
		y -= dimY - ((dimY - h) * 0.5f);
		if (dimY > h && alignX != Alignment::Center)
		{
			y -= (dimY * 0.5f) - h;
			h = dimY - h;
		}
	}

	_sprites.push_back(Sprite {
	    texture,
	    x,
	    y,
	    w,
	    h,
	    P3D::P3DUtil::ConvertColor(multiSprite.GetColor()),
	});
}

void FrontendProject::AddGroup(const P3D::FrontendGroup& group, int32_t resX, int32_t resY)
{
	for (const auto& multiSprite : group.GetMultiSprites()) { AddMultiSprite(*multiSprite, resX, resY); }

	for (const auto& group : group.GetChildren()) { AddGroup(*group, resX, resY); }
}

void FrontendProject::LoadP3D(const std::string& filename)
{
	if (!FileSystem::exists(filename))
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
			auto resX = (int32_t)project->GetResX();
			auto resY = (int32_t)project->GetResY();

			for (const auto& page : project->GetPages())
			{
				if (page->GetName() != "MessageBox.pag")
					continue;

				for (const auto& layer : page->GetLayers())
				{
					for (const auto& group : layer->GetGroups()) { AddGroup(*group, resX, resY); }

					for (const auto& multiSprite : layer->GetMultiSprites()) { AddMultiSprite(*multiSprite, resX, resY); }
				}
			}
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

void FrontendProject::Draw(const Matrix4x4& proj)
{
	for (const auto& sprite : _sprites)
	{
		_spriteBatch.Draw(sprite.texture, Vector2(sprite.positionX, sprite.positionY), Vector2(sprite.width, sprite.height),
		                  sprite.color);
	}

	glBindSampler(0, _sampler);
	_spriteBatch.Flush(proj, 2.0f);
}
} // namespace Donut
