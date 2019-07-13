#include <MemoryStream.h>
#include <P3D/BillboardQuadGroup.h>

namespace Donut::P3D
{
std::unique_ptr<BillboardQuadGroup> BillboardQuadGroup::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::BillboardQuadGroup));

	MemoryStream stream(chunk.GetData());

	auto version   = stream.Read<uint32_t>();
	auto name      = stream.ReadLPString();
	auto shader    = stream.ReadLPString();
	auto zTest     = stream.Read<uint32_t>();
	auto zWrite    = stream.Read<uint32_t>();
	auto fog       = stream.Read<uint32_t>();
	auto quadCount = stream.Read<uint32_t>();

	auto const& children = chunk.GetChildren();

	std::vector<std::unique_ptr<BillboardQuad>> quads;

	for (auto const& child : children)
	{
		MemoryStream data(child->GetData());

		switch (child->GetType())
		{
		case ChunkType::BillboardQuad:
		{
			quads.push_back(BillboardQuad::Load(*child));
			break;
		}
		default: throw std::exception("unexpected child chunk in BillboardQuadGroup");
		}
	}

	return std::make_unique<BillboardQuadGroup>(name, shader, std::move(quads));
}
} // namespace Donut::P3D
