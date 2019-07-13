#include <MemoryStream.h>
#include <P3D/WorldSphere.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<WorldSphere> WorldSphere::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::WorldSphere));

	MemoryStream stream(chunk.GetData());

	const auto name           = stream.ReadLPString();
	const auto version        = stream.Read<uint32_t>();
	const auto meshCount      = stream.Read<uint32_t>();
	const auto billboardCount = stream.Read<uint32_t>();

	assert(version == 0);

	std::vector<std::unique_ptr<Mesh>> meshes;
	//meshes.resize(meshCount);

	for (auto const& child : chunk.GetChildren())
	{
		switch (child->GetType())
		{
		case ChunkType::Mesh:
			meshes.push_back(Mesh::Load(*child));
			break;
		case ChunkType::BillboardQuadGroup:
		case ChunkType::Animation:
		case ChunkType::Skeleton:
		case ChunkType::CompositeDrawable:
		case ChunkType::FrameController:
		case ChunkType::MultiController:
			// todo: handle all this shite
			break;
		default:
			std::cout << "[WorldSphere] Unexpected Chunk: " << child->GetType() << "\n";
		}
	}

	return std::make_unique<WorldSphere>(name, std::move(meshes));
}

} // namespace Donut::P3D
