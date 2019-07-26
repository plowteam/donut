#include <Core/MemoryStream.h>
#include <P3D/InstanceList.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<InstanceList> InstanceList::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::InstanceList));

		MemoryStream stream(chunk.GetData());

		std::string name = stream.ReadLPString();

		std::unique_ptr<SceneGraph> sceneGraph;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::SceneGraph:
				sceneGraph = SceneGraph::Load(*child);
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<InstanceList>(std::move(sceneGraph));
	}
} // namespace Donut::P3D
