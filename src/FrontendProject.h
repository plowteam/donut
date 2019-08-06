// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <string>
#include <memory>
#include <Render/SpriteBatch.h>

namespace Donut
{
	class ResourceManager;
	class Texture;

	class FrontendProject
	{
	public:
		void LoadP3D(const std::string&);
		void Draw(const glm::mat4& proj);

	private:

		SpriteBatch _spriteBatch;
	};
}
