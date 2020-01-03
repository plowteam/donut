// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Vector4.h"

#include <fmt/format.h>
#include <memory>
#include <vector>

namespace Donut::P3D
{
enum class ChunkType : uint32_t
{
	Camera = 0x2200,
	LightGroup = 0x2380,
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
	CompositeDrawableEffect = 0x4518,
	CompositeDrawableSortOrder = 0x4519,
	MultiController = 0x48A0,
	MultiControllerTracks = 0x48A1,
	History = 0x7000,
	ExportInfo = 0x7030,
	ExportInfoNamedString = 0x7031,
	ExportInfoNamedInteger = 0x7032,
	Geometry = 0x10000,
	PolySkin = 0x10001,
	PrimitiveGroup = 0x10002,
	BoundingBox = 0x10003,
	BoundingSphere = 0x10004,
	PositionList = 0x10005,
	NormalList = 0x10006,
	UVList = 0x10007,
	ColorList = 0x10008,
	IndexList = 0x1000A,
	MatrixList = 0x1000B,
	WeightList = 0x1000C,
	MatrixPalette = 0x1000D,
	OffsetList = 0x1000E,
	PackedNormalList = 0x10010,
	VertexShader = 0x10011,
	DrawShadow = 0x10017,
	ExpressionOffsets = 0x10018,
	Shader = 0x11000,
	ShaderTextureParam = 0x11002,
	ShaderIntParam = 0x11003,
	ShaderFloatParam = 0x11004,
	ShaderColorParam = 0x11005,
	GameAttr = 0x12000,
	GameAttrIntParam = 0x12001,
	Light = 0x13000,
	LightDirection = 0x13001,
	LightPosition = 0x13002,
	LightShadow = 0x13004,
	Todo0 = 0x13008,
	Locator = 0x14000,
	ParticleSystemFactory = 0x15800,
	ParticleSystem = 0x15801,
	BaseEmitter = 0x15805,
	SpriteEmitter = 0x15806,
	ParticleAnimation = 0x15808,
	EmitterAnimation = 0x15809,
	GeneratorAnimation = 0x1580A,
	ParticleInstancingInfo = 0x1580B,
	BillboardQuad = 0x17001,
	BillboardQuadGroup = 0x17002,
	BillboardDisplayInfo = 0x17003,
	BillboardPerspectiveInfo = 0x17004,
	FrontendProject = 0x18000,
	FrontendScreen = 0x18001,
	FrontendPage = 0x18002,
	FrontendLayer = 0x18003,
	FrontendGroup = 0x18004,
	FrontendMultiSprite = 0x18006,
	FrontendMultiText = 0x18007,
	FrontendObject = 0x18008,
	FrontendPolygon = 0x18009,
	FrontendStringTextBible = 0x1800B,
	FrontendStringHardCoded = 0x1800C,
	FrontendTextBible = 0x1800D,
	FrontendLanguage = 0x1800E,
	FrontendImageResource = 0x18100,
	FrontendObjectResource = 0x18101,
	FrontendTextStyleResource = 0x18104,
	FrontendTextBibleResource = 0x18105,
	Texture = 0x19000,
	Image = 0x19001,
	ImageData = 0x19002,
	Sprite = 0x19005,
	AnimatedObjectFactory = 0x20000,
	AnimatedObject = 0x20001,
	AnimatedObjectAnimation = 0x20002,
	Expression = 0x21000,
	ExpressionGroup = 0x21001,
	ExpressionMixer = 0x21002,
	TextureFont = 0x22000,
	FontGlyphs = 0x22001,
	SceneGraph = 0x120100,
	SceneGraphRoot = 0x120101,
	SceneGraphBranch = 0x120102,
	SceneGraphTransform = 0x120103,
	SceneGraphVisibility = 0x120104,
	SceneGraphDrawable = 0x120107,
	SceneGraphLightGroup = 0x120109,
	SceneGraphSortOrder = 0x12010A,
	Animation = 0x121000,
	AnimationGroup = 0x121001,
	AnimationGroupList = 0x121002,
	AnimationSize = 0x121004,
	AnimationHeader = 0x121006,
	Float1Channel = 0x121100,
	Float2Channel = 0x121101,
	Vector1Channel = 0x121102,
	Vector2Channel = 0x121103,
	Vector3Channel = 0x121104,
	QuaternionChannel = 0x121105,
	EntityChannel = 0x121107,
	BoolChannel = 0x121108,
	Color = 0x121109,
	IntChannel = 0x12110E,
	ChannelInterpolationMode = 0x121110,
	CompressedQuaternionChannel = 0x121111,
	FrameController = 0x121200,
	FrameController2 = 0x121201,
	MultiController2 = 0x121202,
	Todo1 = 0x121203,
	VectorOffsetList = 0x121301,
	VertexAnimKeyFrame = 0x121304,
	Fence = 0x3000000,
	RoadSegment = 0x3000002,
	Road = 0x3000003,
	Intersection = 0x3000004,
	Locator2 = 0x3000005,
	TriggerVolume = 0x3000006,
	Spline = 0x3000007,
	InstanceList = 0x3000008,
	RoadDataSegment = 0x3000009,
	Todo2 = 0x300000A,
	Path = 0x300000B,
	LocatorMatrix = 0x300000C,
	SurfaceTypeList = 0x300000E,
	FollowCameraData = 0x3000100,
	Set = 0x3000110,
	CollisionEffect = 0x3000600,
	Atc = 0x3000602,
	BreakableObject = 0x3001000,
	InstParticleSystem = 0x3001001,
	StaticEntity = 0x3F00000,
	StaticPhysics = 0x3F00001,
	DynamicPhysics = 0x3F00002,
	Intersect = 0x3F00003,
	Tree = 0x3F00004,
	TreeNode = 0x3F00005,
	TreeNode2 = 0x3F00006,
	FenceWrapper = 0x3F00007,
	AnimCollision = 0x3F00008,
	InstancedStaticEntity = 0x3F00009,
	InstancedStaticPhysics = 0x3F0000A,
	WorldSphere = 0x3F0000B,
	Anim = 0x3F0000C,
	LensFlare = 0x3F0000D,
	AnimDynamicPhysics = 0x3F0000E,
	AnimDynamicPhysicsWrapper = 0x3F0000F,
	AnimObjectWrapper = 0x3F00010,
	CollisionObject = 0x7010000,
	CollisionVolume = 0x7010001,
	CollisionSphere = 0x7010002,
	CollisionCylinder = 0x7010003,
	CollisionOBBoxVolume = 0x7010004,
	CollisionWallVolume = 0x7010005,
	CollisionBBoxVolume = 0x7010006,
	CollisionVector = 0x7010007,
	CollisionVolumeOwner = 0x7010021,
	CollisionVolumeOwnerName = 0x7010022,
	CollisionObjectAttribute = 0x7010023,
	PhysicsObject = 0x7011000,
	PhysicsInertiaMatrix = 0x7011001,
	PhysicsVector = 0x7011002,
	PhysicsJoint = 0x7011020,
	StaticPropData = 0x8020000,
	StaticPropStateData = 0x8020001,
	StaticPropVisibilityData = 0x8020002,
	StaticPropFrameControllerData = 0x8020003,
	StaticPropEventData = 0x8020004,
	StaticPropCallbackData = 0x8020005,
	P3DZRoot = 0x5A443350,
	P3DRoot = 0xFF443350,
};

enum class LocatorType : uint32_t
{
	Event,
	Script,
	Location,
	CarStart,
	Spline,
	ZoneEvent,
	Occlusion,
	Interior,
	Directional,
	ActionEvent,
	FOV,
	Todo0,
	StaticCam,
	PedGroup,
	Coin,
	SpawnPoint
};

std::ostream& operator<<(std::ostream& os, ChunkType chunktype);

class P3DChunk
{
public:
	P3DChunk(const std::vector<uint8_t>&);

	ChunkType GetType() const { return _type; }
	bool IsType(ChunkType type) const { return _type == type; }
	const std::vector<uint8_t>& GetData() const { return _data; }
	size_t GetDataSize() const { return _data.size(); }
	const std::vector<std::unique_ptr<P3DChunk>>& GetChildren() const { return _children; }

protected:
	ChunkType _type;
	std::vector<uint8_t> _data;
	std::vector<std::unique_ptr<P3DChunk>> _children;
};

struct FontGlyph
{
	uint32_t textureId;
	float bottomLeftX;
	float bottomLeftY;
	float topRightX;
	float topRightY;
	float leftBearing;
	float rightBearing;
	float width;
	float advance;
	int32_t id;
};

enum class PrimitiveType : uint32_t
{
	TriangleList,
	TriangleStrip,
	LineList,
	LineStrip,
};

struct ImageDecoder
{
	int width;
	int height;
	int comp;
	std::vector<uint8_t> data;

	static ImageDecoder Decode(const std::vector<uint8_t>& data);
};

struct P3DUtil
{
	static void GetDrawables(const std::unique_ptr<class InstanceList>&, std::vector<class SceneGraphDrawable*>&,
	                         std::vector<Matrix4x4>&);

	static void GetDrawables(const std::unique_ptr<class SceneGraphTransform>&, std::vector<class SceneGraphDrawable*>&,
	                         std::vector<Matrix4x4>&, const Matrix4x4&);

	static std::string GetShaderTexture(const std::unique_ptr<class Shader>&);

	static Vector4 ConvertColor(uint32_t v)
	{
		return Vector4(((v >> 16) & 255) / 255.0f, ((v >> 8) & 255) / 255.0f, ((v & 255)) / 255.0f, ((v >> 24) & 255) / 255.0f);
	}
};

} // namespace Donut::P3D
