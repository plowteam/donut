#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/SceneGraph.h>

namespace Donut::P3D
{
	class InstanceList
	{
	public:

		InstanceList(std::unique_ptr<SceneGraph> sceneGraph) :
			_sceneGraph(std::move(sceneGraph))
		{
		}

		static std::unique_ptr<InstanceList> Load(const P3DChunk&);

		void GetDrawables(std::vector<std::unique_ptr<SceneGraphDrawable>>& drawables)
		{
			_sceneGraph->GetDrawables(drawables);
		}

	private:

		std::unique_ptr<SceneGraph> _sceneGraph;
	};
} // namespace Donut::P3D
