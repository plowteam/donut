#pragma once

#include <P3D/P3DChunk.h>
#include <glm/mat4x4.hpp>

namespace Donut::P3D
{
	class SceneGraphDrawable
	{
	public:

		SceneGraphDrawable(
			const std::string& meshName,
			const glm::mat4& transform) :
			_meshName(meshName),
			_transform(transform)
		{
		}

		static std::unique_ptr<SceneGraphDrawable> Load(const P3DChunk&, const glm::mat4&);

		const std::string& GetMeshName() const { return _meshName; }
		const glm::mat4& GetTransform() const { return _transform; }

	private:

		std::string _meshName;
		glm::mat4 _transform;
	};
} // namespace Donut::P3D
