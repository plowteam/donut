#include <Render/CompositeDrawable.h>
#include <P3D/P3DFile.h>
#include <iostream>

namespace Donut
{
	void CompositeDrawable::LoadP3D(const std::string& filename)
	{
		if (!std::filesystem::exists(filename))
		{
			std::cout << "CompositeDrawable not found: " << filename << "\n";
			return;
		}

		std::cout << "Loading CompositeDrawable: " << filename << "\n";

		const auto p3d = P3D::P3DFile(filename);
		const auto& root = p3d.GetRoot();
		for (const auto& chunk : root.GetChildren())
		{
			switch (chunk->GetType())
			{
				case P3D::ChunkType::CompositeDrawable:
				{
					break;
				}
				case P3D::ChunkType::Skeleton:
				{
					break;
				}
				case P3D::ChunkType::Mesh:
				{
					break;
				}
				default: break;
			}
		}
	}

	void CompositeDrawable::Draw(const ResourceManager& rm, glm::mat4& viewProj)
	{

	}
} // namespace Donut
