#include <Core/MemoryStream.h>
#include <P3D/SceneGraphTransform.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<SceneGraphTransform> SceneGraphTransform::Load(const P3DChunk& chunk, const glm::mat4& parentTransform)
	{
		assert(chunk.IsType(ChunkType::SceneGraphTransform));

		MemoryStream stream(chunk.GetData());

		std::string name = stream.ReadLPString();
		auto numChildren = stream.Read<uint32_t>();

		glm::mat4 transform;
		stream.ReadBytes(reinterpret_cast<uint8_t*>(&transform[0][0]), sizeof(glm::mat4));
		glm::mat4 worldTransform = parentTransform * transform;

		std::vector<std::unique_ptr<SceneGraphTransform>> children;
		std::vector<std::unique_ptr<SceneGraphDrawable>> drawables;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::SceneGraphTransform:
				children.push_back(SceneGraphTransform::Load(*child, worldTransform));
				break;
			case ChunkType::SceneGraphDrawable:
				drawables.push_back(SceneGraphDrawable::Load(*child, worldTransform));
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<SceneGraphTransform>(transform, worldTransform, std::move(children), std::move(drawables));
	}
} // namespace Donut::P3D
