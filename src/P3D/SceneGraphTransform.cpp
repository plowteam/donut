#include <Core/MemoryStream.h>
#include <P3D/SceneGraphTransform.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<SceneGraphTransform> SceneGraphTransform::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::ScenegraphTransform));

		MemoryStream stream(chunk.GetData());

		std::string name = stream.ReadLPString();

		std::vector<std::unique_ptr<SceneGraphTransform>> children;
		std::vector<std::unique_ptr<SceneGraphDrawable>> drawables;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::ScenegraphTransform:
				children.push_back(SceneGraphTransform::Load(*child));
				break;
			case ChunkType::ScenegraphDrawable:
				drawables.push_back(SceneGraphDrawable::Load(*child));
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<SceneGraphTransform>(std::move(children), std::move(drawables));
	}
} // namespace Donut::P3D
