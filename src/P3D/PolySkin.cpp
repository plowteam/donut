#include <Core/MemoryStream.h>
#include <P3D/PolySkin.h>
#include <glm/gtc/type_ptr.inl>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<PolySkin> PolySkin::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::PolySkin));

	MemoryStream stream(chunk.GetData());

	auto name                = stream.ReadLPString();
	const auto version       = stream.Read<uint32_t>();
	auto skeletonName        = stream.ReadLPString();
	const auto numPrimGroups = stream.Read<uint32_t>();

	assert(version == 3);

	std::vector<std::unique_ptr<PrimGroup>> primGroups;
	primGroups.reserve(numPrimGroups);

	glm::vec3 boundingBoxLow  = glm::vec3(0.0f);
	glm::vec3 boundingBoxHigh = glm::vec3(0.0f);
	glm::vec3 boundingSphereCentre = glm::vec3(0.0f);
	float boundingSphereRadius     = 0.0f;

	for (auto const& child : chunk.GetChildren())
	{
		switch (child->GetType())
		{
		case ChunkType::PrimitiveGroup:
			primGroups.push_back(PrimGroup::Load(*child.get()));
			break;
		case ChunkType::BoundingBox:
		{
			const auto data = child->GetData().data();
			boundingBoxLow  = glm::make_vec3(reinterpret_cast<const float*>(data));
			boundingBoxHigh = glm::make_vec3(reinterpret_cast<const float*>(data + 12));
			break;
		}
		case ChunkType::BoundingSphere:
		{
			const auto data = child->GetData().data();
			boundingSphereCentre = glm::make_vec3(reinterpret_cast<const float*>(data));
			boundingSphereRadius = *reinterpret_cast<const float*>(data + 12);
			break;	
		}
		default:
			std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
		}
	}

	return std::make_unique<PolySkin>(name, skeletonName, std::move(primGroups),
	                                  BoundingBox(boundingBoxLow, boundingBoxHigh),
	                                  BoundingSphere(boundingSphereCentre, boundingSphereRadius));
}

} // namespace Donut::P3D
