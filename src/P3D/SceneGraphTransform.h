#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/SceneGraphDrawable.h>
#include <glm/mat4x4.hpp>

namespace Donut::P3D
{
	class SceneGraphTransform
	{
	public:

		SceneGraphTransform(
			const glm::mat4& transform,
			const glm::mat4& worldTransform,
			std::vector<std::unique_ptr<SceneGraphTransform>> children,
			std::vector<std::unique_ptr<SceneGraphDrawable>> drawables) :
			_transform(transform),
			_worldTransform(worldTransform),
			_children(std::move(children)),
			_drawables(std::move(drawables))
		{
		}

		static std::unique_ptr<SceneGraphTransform> Load(const P3DChunk&, const glm::mat4&);

		void GetDrawables(std::vector<std::unique_ptr<SceneGraphDrawable>>& drawables)
		{
			for (auto& drawable : _drawables)
			{
				drawables.push_back(std::move(drawable));
			}

			for (auto& child : _children)
			{
				child->GetDrawables(drawables);
			}
		}

		const glm::mat4& GetLocalTransform() const { return _transform; }
		const glm::mat4& GetWorldTransform() const { return _worldTransform; }

	private:

		glm::mat4 _transform;
		glm::mat4 _worldTransform;
		std::vector<std::unique_ptr<SceneGraphTransform>> _children;
		std::vector<std::unique_ptr<SceneGraphDrawable>> _drawables;
	};
} // namespace Donut::P3D
