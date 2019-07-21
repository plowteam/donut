#include <Core/MemoryStream.h>
#include <P3D/CompositeDrawable.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<CompositeDrawable> CompositeDrawable::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::CompositeDrawable));

		MemoryStream stream(chunk.GetData());

		auto name = stream.ReadLPString();
		auto skeletonName = stream.ReadLPString();

		std::unique_ptr<CompositeDrawablePropList> propList;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::CompositeDrawablePropList:
				propList = CompositeDrawablePropList::Load(*child);
				break;
			case ChunkType::CompositeDrawableSkinList:
				break;
			case ChunkType::CompositeDrawableEffectList:
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<CompositeDrawable>(name, skeletonName, std::move(propList));
	}

	std::unique_ptr<CompositeDrawablePropList> CompositeDrawablePropList::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::CompositeDrawablePropList));

		MemoryStream stream(chunk.GetData());

		auto numElements = stream.Read<uint32_t>();
		std::vector<std::unique_ptr<CompositeDrawableProp>> props;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::CompositeDrawableProp:
				props.push_back(CompositeDrawableProp::Load(*child));
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<CompositeDrawablePropList>(std::move(props));
	}

	std::unique_ptr<CompositeDrawableProp> CompositeDrawableProp::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::CompositeDrawableProp));

		MemoryStream stream(chunk.GetData());

		auto name = stream.ReadLPString();
		auto skeletonJoint = stream.Read<uint32_t>();

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::CompositeDrawableSortOrder:
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<CompositeDrawableProp>(name, skeletonJoint);
	}
} // namespace Donut::P3D
