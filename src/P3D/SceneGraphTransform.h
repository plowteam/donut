#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/SceneGraphDrawable.h>

namespace Donut::P3D
{
	class SceneGraphTransform
	{
	public:

		SceneGraphTransform(
			std::vector<std::unique_ptr<SceneGraphTransform>> children,
			std::vector<std::unique_ptr<SceneGraphDrawable>> drawables) :
			_children(std::move(children)),
			_drawables(std::move(drawables))
		{
		}

		static std::unique_ptr<SceneGraphTransform> Load(const P3DChunk&);

	private:

		std::vector<std::unique_ptr<SceneGraphTransform>> _children;
		std::vector<std::unique_ptr<SceneGraphDrawable>> _drawables;
	};
} // namespace Donut::P3D
