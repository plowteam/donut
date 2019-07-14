#include <Core/MemoryStream.h>
#include <P3D/SkeletonJoint.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<SkeletonJoint> SkeletonJoint::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::SkeletonJoint));

	MemoryStream stream(chunk.GetData());

	std::string name      = stream.ReadLPString();
	uint32_t parent       = stream.Read<uint32_t>();
	int32_t dof           = stream.Read<int32_t>();
	int32_t freeAxis      = stream.Read<int32_t>();
	int32_t primaryAxis   = stream.Read<int32_t>();
	int32_t secondaryAxis = stream.Read<int32_t>();
	int32_t twistAxis     = stream.Read<int32_t>();

	glm::mat4 restPose;
	stream.ReadBytes(reinterpret_cast<uint8_t*>(&restPose[0][0]), sizeof(glm::mat4));

	for (auto const& child : chunk.GetChildren())
	{
		switch (child->GetType())
		{
		case ChunkType::SkeletonJointMirrorMap:
			break;
		case ChunkType::SkeletonJointBonePreserve:
			break;
		default:
			std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
		}
	}

	return std::make_unique<SkeletonJoint>(name, parent, restPose);
}

} // namespace Donut::P3D
