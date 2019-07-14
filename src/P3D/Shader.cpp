#include <Core/MemoryStream.h>
#include <P3D/Shader.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<Shader> Shader::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::Shader));

	MemoryStream stream(chunk.GetData());

	std::string name           = stream.ReadLPString();
	uint32_t version           = stream.Read<uint32_t>();
	std::string pddiShaderName = stream.ReadLPString();
	uint32_t isTrans           = stream.Read<uint32_t>();
	uint32_t vertexNeeds       = stream.Read<uint32_t>();
	uint32_t vertexMask        = stream.Read<uint32_t>();
	uint32_t numParams         = stream.Read<uint32_t>();

	std::string texture;

	for (auto const& child : chunk.GetChildren())
	{
		MemoryStream data(child->GetData());

		switch (child->GetType())
		{
		case ChunkType::ShaderTextureParam:
		{
			auto paramMagic = data.Read<uint32_t>();
			texture         = data.ReadLPString();
			break;
		}
		default:
			break;
		}
	}

	return std::make_unique<Shader>(name, texture);
}

} // namespace Donut::P3D
