// Copyright 2019-2021 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstddef>

namespace donut::pure3d
{

// TODO: Should we support big endian files?
enum class P3DFileType : std::uint32_t
{
	Normal = 0xFF443350,
	Compressed = 0x5A443350,
};

enum class ChunkID : std::uint32_t
{
	Camera = 0x2200,
	LightGroup = 0x2380,

	// Skeleton
	Skeleton = 0x4500,
	SkeletonJoint = 0x4501,
	SkeletonJointPhysics = 0x4502,
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

	// Seems to be left by tools sometimes
	History = 0x7000,
	ExportInfo = 0x7030,
	ExportInfoNamedString = 0x7031,
	ExportInfoNamedInteger = 0x7032,

	// Mesh
	Mesh = 0x10000,
	MeshSkin = 0x10001,
	MeshPrimitiveGroup = 0x10002,
	MeshBoundingBox = 0x10003,
	MeshBoundingSphere = 0x10004,
	MeshPositionList = 0x10005,
	MeshNormalList = 0x10006,
	MeshUVList = 0x10007,
	MeshColourList = 0x10008,
	MeshStripList = 0x10009,
	MeshIndexList = 0x1000A,
	MeshMatrixList = 0x1000B,
	MeshWeightList = 0x1000C,
	MeshMatrixPalette = 0x1000D,
	MeshOffsetList = 0x1000E,
	MeshInstanceInfo = 0x1000F,
	MeshPackedNormalList = 0x10010,
	MeshVertexShader = 0x10011,
	// const unsigned MEMORYIMAGEVERTEXLIST = 0x00010012;
	// const unsigned MEMORYIMAGEINDEXLIST = 0x00010013;
	// const unsigned MEMORYIMAGEVERTEXDESCRIPTIONLIST = 0x00010014;
	// const unsigned TANGENTLIST = 0x00010015;
	// const unsigned BINORMALLIST = 0x00010016;
	RenderStatus = 0x10017,
	ExpressionOffsets = 0x10018,
	// const unsigned SHADOWSKIN = 0x00010019;
	// const unsigned SHADOWMESH = 0x0001001A;
	// const unsigned TOPOLOGY = 0x0001001B;
	// const unsigned MULTICOLOURLIST = 0x0001001C;

	// Shader
	Shader = 0x11000,
	ShaderDefinition = 0x11001,
	ShaderTextureParameter = 0x11002,
	ShaderIntParameter = 0x11003,
	ShaderFloatParameter = 0x11004,
	ShaderColourParameter = 0x11005,
	ShaderVectorParameter = 0x11006,
	ShaderMatrixParameter = 0x11007,

	// GameAttr
	GameAttr = 0x12000,
	GameAttrIntParam = 0x12001,
	GameAttrFloatParam = 0x12002,
	GameAttrColourParam = 0x12003,
	GameAttrVectorParam = 0x12004,
	GameAttrMatrixParam = 0x12005,

	// Light
	Light = 0x13000,
	LightDirection = 0x13001,
	LightPosition = 0x13002,
	LightConeParam = 0x13003,
	LightShadow = 0x13004,
	LightPhotonMap = 0x13005,
	LightDecayRange = 0x13006,
	LightDecayRangeRotationY = 0x13007,
	LightIlluminationType = 0x13008,

	// Locator
	Locator = 0x14000,

	// ParticleSystem (Starts at 0x15800, later then others?)
	ParticleSystemFactory = 0x15800,
	ParticleSystem = 0x15801,
	ParticleSystemBaseEmitter = 0x15805,
	ParticleSystemSpriteEmitter = 0x15806,
	ParticleSystemDrawableEmitter = 0x15807,
	ParticleSystemParticleAnimation = 0x15808,
	ParticleSystemEmitterAnimation = 0x15809,
	ParticleSystemGeneratorAnimation = 0x1580A,
	ParticleSystemInstancingInfo = 0x1580B,

	// TODO: Missing 0x16000? (Is this used anywhere?)

	// Billboard
	BillboardQuad = 0x17001,
	BillboardQuadGroup = 0x17002,
	BillboardDisplayInfo = 0x17003,
	BillboardPerspectiveInfo = 0x17004,

	// Frontend (Scrooby)
	FrontendProject = 0x18000,
	FrontendScreen = 0x18001,
	FrontendPage = 0x18002,
	FrontendLayer = 0x18003,
	FrontendGroup = 0x18004,
	FrontendMovie = 0x18005,
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

	// Texture
	Texture = 0x19000,
	TextureImage = 0x19001,
	TextureImageData = 0x19002,
	TextureVolumeImage = 0x19004,
	TextureSprite = 0x19005,

	// AnimatedObject
	AnimatedObjectFactory = 0x20000,
	AnimatedObject = 0x20001,
	AnimatedObjectAnimation = 0x20002,

	// Expression
	Expression = 0x21000,
	ExpressionGroup = 0x21001,
	ExpressionMixer = 0x21002,

	// TextureFont
	TextureFont = 0x22000,
	TextureFontGlyphs = 0x22001,

	// SceneGraph
	SceneGraph = 0x120100,
	SceneGraphRoot = 0x120101,
	SceneGraphBranch = 0x120102,
	SceneGraphTransform = 0x120103,
	SceneGraphVisibility = 0x120104,
	SceneGraphDrawable = 0x120107,
	SceneGraphLightGroup = 0x120109,
	SceneGraphSortOrder = 0x12010A,

	// Animation
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

	// Simpsons specific chunks (seems way messier then the rest)
	Wall = 0x3000000,
	FenceLine = 0x3000000,
	RoadSegment = 0x3000002,
	Road = 0x3000003,
	Intersection = 0x3000004,
	Locator2 = 0x3000005,
	TriggerVolume = 0x3000006,
	Spline = 0x3000007,
	InstanceList = 0x3000008,
	RoadDataSegment = 0x3000009,
	Rail = 0x300000A,
	PedPath = 0x300000B,
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

	// Collision
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

	// Physics
	PhysicsObject = 0x7011000,
	PhysicsInertiaMatrix = 0x7011001,
	PhysicsVector = 0x7011002,
	PhysicsJoint = 0x7011020,

	// StaticProp
	StaticPropData = 0x8020000,
	StaticPropStateData = 0x8020001,
	StaticPropVisibilityData = 0x8020002,
	StaticPropFrameControllerData = 0x8020003,
	StaticPropEventData = 0x8020004,
	StaticPropCallbackData = 0x8020005,
};

} // namespace donut::pure3d
