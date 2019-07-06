#include <Pure3D/Chunk.h>

#include <iostream>

namespace Donut::Pure3D
{

std::ostream& operator<< (std::ostream& os, ChunkType chunktype)
{
	switch (chunktype)
	{
	case ChunkType::Camera: return os << "Camera";
	case ChunkType::Skeleton: return os << "Skeleton";
	case ChunkType::SkeletonJoint: return os << "SkeletonJoint";
	case ChunkType::SkeletonJointMirrorMap: return os << "SkeletonJointMirrorMap";
	case ChunkType::SkeletonJointBonePreserve: return os << "SkeletonJointBonePreserve";
	case ChunkType::CompositeDrawable: return os << "CompositeDrawable";
	case ChunkType::CompositeDrawableSkinList: return os << "CompositeDrawableSkinList";
	case ChunkType::CompositeDrawablePropList: return os << "CompositeDrawablePropList";
	case ChunkType::CompositeDrawableSkin: return os << "CompositeDrawableSkin";
	case ChunkType::CompositeDrawableProp: return os << "CompositeDrawableProp";
	case ChunkType::CompositeDrawableEffectList: return os << "CompositeDrawableEffectList";
	case ChunkType::CompositeDrawableSortOrder: return os << "CompositeDrawableSortOrder";
	case ChunkType::Mesh: return os << "Mesh";
	case ChunkType::Skin: return os << "Skin";
	case ChunkType::PrimitiveGroup: return os << "PrimitiveGroup";
	case ChunkType::BoundingBox: return os << "BoundingBox";
	case ChunkType::BoundingSphere: return os << "BoundingSphere";
	case ChunkType::PositionList: return os << "PositionList";
	case ChunkType::NormalList: return os << "NormalList";
	case ChunkType::UVList: return os << "UVList";
	case ChunkType::ColourList: return os << "ColourList";
	case ChunkType::IndexList: return os << "IndexList";
	case ChunkType::MatrixList: return os << "MatrixList";
	case ChunkType::WeightList: return os << "WeightList";
	case ChunkType::MatrixPalette: return os << "MatrixPalette";
	case ChunkType::PackedNormalList: return os << "PackedNormalList";
	case ChunkType::VertexShader: return os << "VertexShader";
	case ChunkType::Shader: return os << "Shader";
	case ChunkType::ShaderTextureParam: return os << "ShaderTextureParam";
	case ChunkType::ShaderIntParam: return os << "ShaderIntParam";
	case ChunkType::ShaderFloatParam: return os << "ShaderFloatParam";
	case ChunkType::ShaderColourParam: return os << "ShaderColourParam";
	case ChunkType::Locator: return os << "Locator";
	case ChunkType::ParticleSystemFactory: return os << "ParticleSystemFactory";
	case ChunkType::BaseEmitter: return os << "BaseEmitter";
	case ChunkType::SpriteEmitter: return os << "SpriteEmitter";
	case ChunkType::ParticleAnimation: return os << "ParticleAnimation";
	case ChunkType::ParticleInstancingInfo: return os << "ParticleInstancingInfo";
	case ChunkType::BillboardQuad: return os << "BillboardQuad";
	case ChunkType::BillboardQuadGroup: return os << "BillboardQuadGroup";
	case ChunkType::BillboardDisplayInfo: return os << "BillboardDisplayInfo";
	case ChunkType::BillboardPerspectiveInfo: return os << "BillboardPerspectiveInfo";
	case ChunkType::Texture: return os << "Texture";
	case ChunkType::Image: return os << "Image";
	case ChunkType::ImageData: return os << "ImageData";
	case ChunkType::Animation: return os << "Animation";
	case ChunkType::AnimationGroup: return os << "AnimationGroup";
	case ChunkType::AnimationGroupList: return os << "AnimationGroupList";
	case ChunkType::AnimationSize: return os << "AnimationSize";
	case ChunkType::Vector1Channel: return os << "Vector1Channel";
	case ChunkType::Vector2Channel: return os << "Vector2Channel";
	case ChunkType::Vector3Channel: return os << "Vector3Channel";
	case ChunkType::QuaternionChannel: return os << "QuaternionChannel";
	case ChunkType::ChannelInterpolationMode: return os << "ChannelInterpolationMode";
	case ChunkType::CompressedQuaternionChannel: return os << "CompressedQuaternionChannel";
	case ChunkType::CarCameraData: return os << "CarCameraData";
	case ChunkType::PhysicsObject: return os << "PhysicsObject";
	case ChunkType::PhysicsInertiaMatrix: return os << "PhysicsInertiaMatrix";
	case ChunkType::PhysicsVector: return os << "PhysicsVector";
	case ChunkType::PhysicsJoint: return os << "PhysicsJoint";
	case ChunkType::P3DRoot: return os << "P3DRoot";
	};
	return os << static_cast<std::uint32_t>(chunktype);
}

Chunk::Chunk()
{

}

Chunk::~Chunk()
{

}

// indentLevel is for debug, remove it after
void Chunk::Read(File& file, int indentLevel)
{
	file.Read<uint32_t>(&_type, 1);
	file.Read<uint32_t>(&_dataSize, 1);
	file.Read<uint32_t>(&_totalSize, 1);

	std::cout << std::hex << std::showbase <<
		std::string(indentLevel, '\t') + "Type: " << static_cast<ChunkType>(_type) << "\n"
		+ std::string(indentLevel, '\t') + "Data Size: " << _dataSize << "\n"
		+ std::string(indentLevel, '\t') + "ChildrenSize: " << _totalSize - _dataSize << "\n";

	// seek over the data
	file.Seek(_dataSize - 12, FileSeekMode::Current);

	readChildren(file, indentLevel + 1);
}

void Chunk::readChildren(File& file, int indentLevel)
{
	uint32_t childrenSize = _totalSize - _dataSize;

	if (childrenSize <= 0)
		return;

	uint32_t endPos = file.Position() + childrenSize;
	while (file.Position() < endPos)
	{
		_children.push_back(std::make_unique<Chunk>());
		_children.back()->Read(file, indentLevel);
	}
}

}
