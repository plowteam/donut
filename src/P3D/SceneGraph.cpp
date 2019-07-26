#include <Core/MemoryStream.h>
#include <P3D/SceneGraph.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<SceneGraph> SceneGraph::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::SceneGraph));

		MemoryStream stream(chunk.GetData());

		std::string name = stream.ReadLPString();

		std::unique_ptr<SceneGraphRoot> root;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::SceneGraphRoot:
				root = SceneGraphRoot::Load(*child);
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<SceneGraph>(std::move(root));
	}

	std::unique_ptr<SceneGraphRoot> SceneGraphRoot::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::SceneGraphRoot));

		MemoryStream stream(chunk.GetData());

		std::unique_ptr<SceneGraphBranch> branch;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::SceneGraphBranch:
				branch = SceneGraphBranch::Load(*child);
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<SceneGraphRoot>(std::move(branch));
	}

	std::unique_ptr<SceneGraphBranch> SceneGraphBranch::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::SceneGraphBranch));

		MemoryStream stream(chunk.GetData());

		std::string name = stream.ReadLPString();

		std::vector<std::unique_ptr<SceneGraphTransform>> children;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::SceneGraphTransform:
				children.push_back(SceneGraphTransform::Load(*child, glm::mat4(1.0f)));
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<SceneGraphBranch>(name, std::move(children));
	}
} // namespace Donut::P3D
