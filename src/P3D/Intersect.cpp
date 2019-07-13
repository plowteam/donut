#include <MemoryStream.h>
#include <P3D/Intersect.h>
#include <glm/gtc/type_ptr.inl>

namespace Donut::P3D
{
std::unique_ptr<Intersect> Intersect::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::Intersect));

	MemoryStream stream(chunk.GetData());

	const auto indicesCount = stream.Read<uint32_t>();
	std::vector<uint32_t> indices(indicesCount);
	stream.ReadBytes(reinterpret_cast<uint8_t*>(indices.data()), indicesCount * sizeof(uint32_t));

	const auto positionsCount = stream.Read<uint32_t>();
	std::vector<glm::vec3> positions(positionsCount);
	stream.ReadBytes(reinterpret_cast<uint8_t*>(positions.data()), positionsCount * sizeof(glm::vec3));

	const auto normalsCount = stream.Read<uint32_t>();
	std::vector<glm::vec3> normals(normalsCount);
	stream.ReadBytes(reinterpret_cast<uint8_t*>(normals.data()), normalsCount * sizeof(glm::vec3));

	glm::vec3 min, max;
	for (auto const& child : chunk.GetChildren())
	{
		if (!child->IsType(ChunkType::BoundingBox))
			continue;

		min = glm::make_vec3(reinterpret_cast<const float*>(child->GetData().data()));
		max = glm::make_vec3(reinterpret_cast<const float*>(child->GetData().data() + 12));
	}

	return std::make_unique<Intersect>(positions, indices, normals, AABB(min, max));
}
} // namespace Donut::P3D
