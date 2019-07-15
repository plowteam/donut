#include <Core/MemoryStream.h>
#include <P3D/StaticPhys.h>

namespace Donut::P3D
{

std::unique_ptr<StaticPhys> StaticPhys::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::StaticPhysics));

	MemoryStream stream(chunk.GetData());

	std::string name     = stream.ReadLPString();

	auto const& children = chunk.GetChildren();

	// should just be a CollisionObject chunk and a 0x3000600
	assert(!children.empty());

	auto const& objChunk = children.at(0);
	assert(objChunk->IsType(ChunkType::CollisionObject));

	auto obj = CollisionObject::Load(*objChunk);
	return std::make_unique<StaticPhys>(name, std::move(obj));
}

} // namespace Donut::P3D
