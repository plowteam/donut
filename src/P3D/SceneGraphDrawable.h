#pragma once

#include <P3D/P3DChunk.h>

namespace Donut::P3D
{
	class SceneGraphDrawable
	{
	public:

		SceneGraphDrawable(
			const std::string& meshName) :
			_meshName(meshName)
		{
		}

		static std::unique_ptr<SceneGraphDrawable> Load(const P3DChunk&);

		const std::string& GetMeshName() const { return _meshName; }

	private:

		std::string _meshName;
	};
} // namespace Donut::P3D
