#include <Core/MemoryStream.h>
#include <P3D/InstancedStaticPhys.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<InstancedStaticPhys> InstancedStaticPhys::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::InstancedStaticPhysics));

		MemoryStream stream(chunk.GetData());

		std::string name = stream.ReadLPString();

		std::vector<std::unique_ptr<Mesh>> meshes;
		std::unique_ptr<InstanceList> instanceList;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::Mesh:
				meshes.push_back(Mesh::Load(*child));
				break;
			case ChunkType::InstanceList:
				instanceList = InstanceList::Load(*child);
				break;
			case ChunkType::CollisionObject:
				break;
			case ChunkType::CollisionEffect:
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<InstancedStaticPhys>(
			name,
			std::move(meshes),
			std::move(instanceList));
	}
} // namespace Donut::P3D
