#include <MemoryStream.h>
#include <P3D/StaticEntity.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<StaticEntity> StaticEntity::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::StaticEntity));

	MemoryStream stream(chunk.GetData());

	std::string name     = stream.ReadLPString();
	uint32_t version     = stream.Read<uint32_t>();
	uint32_t renderOrder = stream.Read<uint32_t>();

	auto const& children = chunk.GetChildren();

	// should just be a Mesh chunk
	assert(children.size() == 1);

	auto const& meshChunk = children.at(0);
	assert(meshChunk->IsType(ChunkType::Mesh));

	auto mesh = Mesh::Load(*meshChunk);
	return std::make_unique<StaticEntity>(name, std::move(mesh));
}

} // namespace Donut::P3D
