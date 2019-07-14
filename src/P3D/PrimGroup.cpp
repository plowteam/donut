#include <Core/MemoryStream.h>
#include <P3D/PrimGroup.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<PrimGroup> PrimGroup::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::PrimitiveGroup));

	MemoryStream stream(chunk.GetData());

	uint32_t version                  = stream.Read<uint32_t>(); // should be 0
	std::string shaderName            = stream.ReadLPString();
	PrimGroup::PrimitiveType primType = stream.Read<PrimGroup::PrimitiveType>();
	uint32_t hasDataFlags             = stream.Read<uint32_t>();
	uint32_t numVerts                 = stream.Read<uint32_t>();
	uint32_t numIndices               = stream.Read<uint32_t>();
	uint32_t numMatrices              = stream.Read<uint32_t>();

	std::unique_ptr<PrimGroup> primGroup = std::make_unique<PrimGroup>(shaderName, primType);

	for (auto const& child : chunk.GetChildren())
	{
		MemoryStream data(child->GetData());

		switch (child->GetType())
		{
		case ChunkType::PositionList:
		{
			uint32_t len = data.Read<uint32_t>();

			auto& verts = primGroup->GetVerticies();
			verts.resize(len);
			data.ReadBytes(reinterpret_cast<uint8_t*>(verts.data()), len * sizeof(glm::vec3));
			break;
		}
		case ChunkType::IndexList:
		{
			uint32_t len = data.Read<uint32_t>();

			auto& indices = primGroup->GetIndices();
			indices.resize(len);
			data.ReadBytes(reinterpret_cast<uint8_t*>(indices.data()), len * sizeof(uint32_t));
			break;
		}
		case ChunkType::NormalList:
		{
			uint32_t len = data.Read<uint32_t>();

			auto& normals = primGroup->GetNormals();
			normals.resize(len);
			data.ReadBytes(reinterpret_cast<uint8_t*>(normals.data()), len * sizeof(glm::vec3));
			break;
		}
		case ChunkType::UVList:
		{
			uint32_t len     = data.Read<uint32_t>();
			uint32_t channel = data.Read<uint32_t>();

			auto& uvs = primGroup->GetUV();
			uvs.resize(len);
			data.ReadBytes(reinterpret_cast<uint8_t*>(uvs.data()), len * sizeof(glm::vec2));
			break;
		}
		case ChunkType::MatrixList:
		{
			uint32_t len = data.Read<uint32_t>();

			auto& matrixList = primGroup->GetMatrixList();
			matrixList.resize(len * 4);
			data.ReadBytes(reinterpret_cast<uint8_t*>(matrixList.data()), matrixList.size());
			break;
		}
		case ChunkType::WeightList:
		{
			uint32_t len = data.Read<uint32_t>();

			auto& weights = primGroup->GetWeights();
			weights.resize(len);
			data.ReadBytes(reinterpret_cast<uint8_t*>(weights.data()), len * sizeof(glm::vec3));
			break;
		}
		case ChunkType::MatrixPalette:
		{
			uint32_t len = data.Read<uint32_t>();

			auto& matrixPalette = primGroup->GetMatrixPalette();
			matrixPalette.resize(len);
			data.ReadBytes(reinterpret_cast<uint8_t*>(matrixPalette.data()), len * sizeof(uint32_t));
			break;
		}
		case ChunkType::ColourList:
		{
			uint32_t len = data.Read<uint32_t>();

			auto& colorList = primGroup->GetColors();
			colorList.resize(len);
			data.ReadBytes(reinterpret_cast<uint8_t*>(colorList.data()), len * sizeof(uint32_t));
			break;
		}
		case ChunkType::VertexShader: 
		{
			auto vertexShader = data.ReadLPString(); // always "" ?
			// std::cout << "VertexShader: " << vertexShader << "\n";
			break;
		}
		// expect all this
		case ChunkType::PackedNormalList:
			break;
		default:
			std::cout << "[PrimGroup] Unexpected Chunk: " << child->GetType() << "\n";
		}
	}

	return primGroup;
}

} // namespace Donut::P3D
