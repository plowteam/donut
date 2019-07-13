#include <MemoryStream.h>
#include <P3D/BillboardQuad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace Donut::P3D
{
std::unique_ptr<BillboardQuad> BillboardQuad::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::BillboardQuad));

	MemoryStream stream(chunk.GetData());

	auto version = stream.Read<uint32_t>();
	auto name    = stream.ReadLPString();
	auto mode    = stream.ReadString(4);
	auto translation = glm::vec3();

	stream.ReadBytes(reinterpret_cast<uint8_t*>(&translation[0]), sizeof(glm::vec3));
	auto color = stream.Read<uint32_t>();

	glm::vec2 uv0, uv1, uv2, uv3, uvoffset = glm::vec2();

	stream.ReadBytes(reinterpret_cast<uint8_t*>(&uv0[0]), sizeof(glm::vec2));
	stream.ReadBytes(reinterpret_cast<uint8_t*>(&uv1[0]), sizeof(glm::vec2));
	stream.ReadBytes(reinterpret_cast<uint8_t*>(&uv2[0]), sizeof(glm::vec2));
	stream.ReadBytes(reinterpret_cast<uint8_t*>(&uv3[0]), sizeof(glm::vec2));

	auto width = stream.Read<float>();
	auto height = stream.Read<float>();
	auto distance = stream.Read<float>();

	stream.ReadBytes(reinterpret_cast<uint8_t*>(&uvoffset[0]), sizeof(glm::vec2));

	return std::make_unique<BillboardQuad>(name);
}
} // namespace Donut::P3D
