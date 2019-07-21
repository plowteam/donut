#pragma once

#include <Render/Mesh.h>
#include <ResourceManager.h>
#include <string>
#include <glm/mat4x4.hpp>

namespace Donut
{
	class CompositeModel
	{
	public:

		CompositeModel();

		void Draw(GL::ShaderProgram& shader, const glm::mat4& viewProj, const glm::mat4& modelMatrix);
		void LoadP3D(const std::string& filename);

	private:

		struct DrawableProp
		{
			size_t meshIndex;
			glm::mat4 transform;
		};

		std::vector<std::unique_ptr<Mesh>> _meshes;
		std::vector<DrawableProp> _props;
		std::unique_ptr<ResourceManager> _resourceManager;
	};
} // namespace Donut
