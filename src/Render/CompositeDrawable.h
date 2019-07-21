#pragma once

#include <Render/Mesh.h>
#include <ResourceManager.h>
#include <string>

namespace Donut
{
	class CompositeDrawable
	{
	public:

		void Draw(const ResourceManager&, glm::mat4& viewProj);
		void LoadP3D(const std::string& filename);

	private:

	};
} // namespace Donut
