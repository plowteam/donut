#pragma once

#include <File.h>
#include <memory>
#include <vector>

namespace Donut::Pure3D
{

enum class ChunkType : uint32_t {
	Camera = 0x2200,
	Skeleton = 0x4500,
	SkeletonJoint = 0x4501,
	SkeletonJointMirrorMap = 0x4503,
	SkeletonJointBonePreserve = 0x4504,
	CompositeDrawable = 0x4512,
	CompositeDrawableSkinList = 0x4513,
	CompositeDrawablePropList = 0x4514,
	CompositeDrawableSkin = 0x4515,
	CompositeDrawableProp = 0x4516,
	CompositeDrawableEffectList = 0x4517,
	CompositeDrawableSortOrder = 0x4519,
	Mesh = 0x10000,
	Skin = 0x10001,
	PrimitiveGroup = 0x10002,
	BoundingBox = 0x10003,
	BoundingSphere = 0x10004,
	PositionList = 0x10005,
	NormalList = 0x10006,
	UVList = 0x10007,
	ColourList = 0x10008,
	IndexList = 0x1000A,
	MatrixList = 0x1000B,
	WeightList = 0x1000C,
	MatrixPalette = 0x1000D,
	PackedNormalList = 0x10010,
	VertexShader = 0x10011,
	Shader = 0x11000,
	ShaderTextureParam = 0x11002,
	ShaderIntParam = 0x11003,
	ShaderFloatParam = 0x11004,
	ShaderColourParam = 0x11005,
	Locator = 0x14000,
	ParticleSystemFactory = 0x15800,
	BaseEmitter = 0x15805,
	SpriteEmitter = 0x15806,
	ParticleAnimation = 0x15808,
	ParticleInstancingInfo = 0x1580B,
	BillboardQuad = 0x17001,
	BillboardQuadGroup = 0x17002,
	BillboardDisplayInfo = 0x17003,
	BillboardPerspectiveInfo = 0x17004,
	Texture = 0x19000,
	Image = 0x19001,
	ImageData = 0x19002,
	Animation = 0x121000,
	AnimationGroup = 0x121001,
	AnimationGroupList = 0x121002,
	AnimationSize = 0x121004,
	Vector1Channel = 0x121102,
	Vector2Channel = 0x121103,
	Vector3Channel = 0x121104,
	QuaternionChannel = 0x121105,
	ChannelInterpolationMode = 0x121110,
	CompressedQuaternionChannel = 0x121111,
	CarCameraData = 0x3000100,
	PhysicsObject = 0x7011000,
	PhysicsInertiaMatrix = 0x7011001,
	PhysicsVector = 0x7011002,
	PhysicsJoint = 0x7011020,

	P3DRoot = 0xFF443350,
};

class Chunk
{
public:
	Chunk();
	~Chunk();
	void Read(File&, int indentLevel);
protected:
	void readChildren(File&, int indentLevel);

	std::uint32_t _type;
	std::uint32_t _dataSize;
	std::uint32_t _totalSize;

	Chunk* _parent;
	std::vector<std::unique_ptr<Chunk>> _children;
};

} // namespace Donut::Pure3D
