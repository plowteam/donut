#include "Shader.h"

#include <MemoryStream.h>
#include <P3D/Mesh.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<Mesh> Mesh::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::Mesh));

	MemoryStream stream(chunk.GetData());

	auto name          = stream.ReadLPString();
	auto version       = stream.Read<uint32_t>();
	auto numPrimGroups = stream.Read<uint32_t>();

	auto const& children = chunk.GetChildren();

	// there should be a bounding box, bounding sphere and draw shadow status
	//assert(numPrimGroups == children.size());

	std::vector<std::unique_ptr<PrimGroup>> primGroups;

	for (auto const& child : children)
	{
		MemoryStream data(child->GetData());

		switch (child->GetType())
		{
		case ChunkType::PrimitiveGroup:
		{
			primGroups.push_back(PrimGroup::Load(*child));
			break;
		}
		case ChunkType::BoundingBox:
		case ChunkType::BoundingSphere:
		case ChunkType::DrawShadow:
			break;
		default:
			throw std::exception("unexpected child chunk in Mesh");
		}
	}

	return std::make_unique<Mesh>(name, std::move(primGroups));
}

} // namespace Donut::P3D
