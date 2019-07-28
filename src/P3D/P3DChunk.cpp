#include <P3D/P3DChunk.h>
#include <P3D/p3d.generated.h>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include <ThirdParty/stb_image.h>

namespace Donut::P3D
{
	// just does png for now
	ImageData ImageData::Decode(const std::vector<uint8_t>& data)
	{
		ImageData ret;
		uint8_t* image = stbi_load_from_memory(data.data(), (std::int32_t)data.size(), &ret.width, &ret.height, &ret.comp, 0);
		ret.data = std::vector<uint8_t>(image, image + (ret.width * ret.height * ret.comp));
		stbi_image_free(image);

		return ret;
	}

	void P3DUtil::GetDrawables(
		const std::unique_ptr<InstanceList>& instanceList,
		std::vector<SceneGraphDrawable*>& drawables,
		std::vector<glm::mat4>& transforms)
	{
		if (!instanceList) return;

		const auto& sceneGraph = instanceList->GetSceneGraph();
		if (!sceneGraph) return;
		const auto& sceneGraphRoot = sceneGraph->GetRoot();
		if (!sceneGraphRoot) return;
		const auto& sceneGraphBranch = sceneGraphRoot->GetBranch();
		if (!sceneGraphBranch) return;

		for (const auto& child : sceneGraphBranch->GetChildren())
		{
			GetDrawables(child, drawables, transforms, glm::mat4(1.0f));
		}
	}

	void P3DUtil::GetDrawables(
		const std::unique_ptr<SceneGraphTransform>& transform,
		std::vector<SceneGraphDrawable*>& drawables,
		std::vector<glm::mat4>& transforms,
		const glm::mat4& parentTransform)
	{
		if (!transform) return;

		const auto worldTransform = parentTransform * transform->GetTransform();

		for (const auto& drawable : transform->GetDrawables())
		{
			drawables.push_back(drawable.get());
			transforms.push_back(worldTransform);
		}

		for (const auto& child : transform->GetChildren())
		{
			GetDrawables(child, drawables, transforms, worldTransform);
		}
	}

P3DChunk::P3DChunk(const std::vector<uint8_t>& chunk)
{
	// minimum size of a chunk
	assert(chunk.size() >= 12);

	_type = *reinterpret_cast<const ChunkType*>(&chunk[0]);

	const uint32_t dataSize  = *reinterpret_cast<const uint32_t*>(&chunk[4]);
	const uint32_t totalSize = *reinterpret_cast<const uint32_t*>(&chunk[8]);

	// define our data and ignore the first 12 bytes
	_data = std::vector<uint8_t>(chunk.begin() + 12, chunk.begin() + dataSize);

	auto it = std::next(chunk.begin(), dataSize);
	while (it < chunk.end())
	{
		// cheat a little and get the chunks size so we can advance our stream
		const uint32_t tSize = *reinterpret_cast<const uint32_t*>(&it[8]);

		const auto cChunkData = std::vector<uint8_t>(it, std::next(it, tSize));
		_children.push_back(std::make_unique<P3DChunk>(cChunkData));

		std::advance(it, tSize);
	}
}

std::ostream& operator<<(std::ostream& os, ChunkType chunktype)
{
	switch (chunktype)
	{
		case ChunkType::Camera:
			return os << "Camera";
		case ChunkType::LightGroup:
			return os << "LightGroup";
		case ChunkType::Skeleton:
			return os << "Skeleton";
		case ChunkType::SkeletonJoint:
			return os << "SkeletonJoint";
		case ChunkType::SkeletonJointMirrorMap:
			return os << "SkeletonJointMirrorMap";
		case ChunkType::SkeletonJointBonePreserve:
			return os << "SkeletonJointBonePreserve";
		case ChunkType::CompositeDrawable:
			return os << "CompositeDrawable";
		case ChunkType::CompositeDrawableSkinList:
			return os << "CompositeDrawableSkinList";
		case ChunkType::CompositeDrawablePropList:
			return os << "CompositeDrawablePropList";
		case ChunkType::CompositeDrawableSkin:
			return os << "CompositeDrawableSkin";
		case ChunkType::CompositeDrawableProp:
			return os << "CompositeDrawableProp";
		case ChunkType::CompositeDrawableEffectList:
			return os << "CompositeDrawableEffectList";
		case ChunkType::CompositeDrawableEffect:
			return os << "CompositeDrawableEffect";
		case ChunkType::CompositeDrawableSortOrder:
			return os << "CompositeDrawableSortOrder";
		case ChunkType::MultiController:
			return os << "MultiController";
		case ChunkType::MultiControllerTracks:
			return os << "MultiControllerTracks";
		case ChunkType::History:
			return os << "History";
		case ChunkType::ExportInfo:
			return os << "ExportInfo";
		case ChunkType::ExportInfoNamedString:
			return os << "ExportInfoNamedString";
		case ChunkType::ExportInfoNamedInteger:
			return os << "ExportInfoNamedInteger";
		case ChunkType::Mesh:
			return os << "Mesh";
		case ChunkType::PolySkin:
			return os << "PolySkin";
		case ChunkType::PrimitiveGroup:
			return os << "PrimitiveGroup";
		case ChunkType::BoundingBox:
			return os << "BoundingBox";
		case ChunkType::BoundingSphere:
			return os << "BoundingSphere";
		case ChunkType::PositionList:
			return os << "PositionList";
		case ChunkType::NormalList:
			return os << "NormalList";
		case ChunkType::UVList:
			return os << "UVList";
		case ChunkType::ColorList:
			return os << "ColorList";
		case ChunkType::IndexList:
			return os << "IndexList";
		case ChunkType::MatrixList:
			return os << "MatrixList";
		case ChunkType::WeightList:
			return os << "WeightList";
		case ChunkType::MatrixPalette:
			return os << "MatrixPalette";
		case ChunkType::OffsetList:
			return os << "OffsetList";
		case ChunkType::PackedNormalList:
			return os << "PackedNormalList";
		case ChunkType::VertexShader:
			return os << "VertexShader";
		case ChunkType::DrawShadow:
			return os << "DrawShadow";
		case ChunkType::ExpressionOffsets:
			return os << "ExpressionOffsets";
		case ChunkType::Shader:
			return os << "Shader";
		case ChunkType::ShaderTextureParam:
			return os << "ShaderTextureParam";
		case ChunkType::ShaderIntParam:
			return os << "ShaderIntParam";
		case ChunkType::ShaderFloatParam:
			return os << "ShaderFloatParam";
		case ChunkType::ShaderColorParam:
			return os << "ShaderColorParam";
		case ChunkType::GameAttr:
			return os << "GameAttr";
		case ChunkType::GameAttrIntParam:
			return os << "GameAttrIntParam";
		case ChunkType::Light:
			return os << "Light";
		case ChunkType::LightDirection:
			return os << "LightDirection";
		case ChunkType::LightPosition:
			return os << "LightPosition";
		case ChunkType::LightShadow:
			return os << "LightShadow";
		case ChunkType::Unknown0:
			return os << "Unknown0";
		case ChunkType::Locator:
			return os << "Locator";
		case ChunkType::ParticleSystemFactory:
			return os << "ParticleSystemFactory";
		case ChunkType::ParticleSystem:
			return os << "ParticleSystem";
		case ChunkType::BaseEmitter:
			return os << "BaseEmitter";
		case ChunkType::SpriteEmitter:
			return os << "SpriteEmitter";
		case ChunkType::ParticleAnimation:
			return os << "ParticleAnimation";
		case ChunkType::EmitterAnimation:
			return os << "EmitterAnimation";
		case ChunkType::GeneratorAnimation:
			return os << "GeneratorAnimation";
		case ChunkType::ParticleInstancingInfo:
			return os << "ParticleInstancingInfo";
		case ChunkType::BillboardQuad:
			return os << "BillboardQuad";
		case ChunkType::BillboardQuadGroup:
			return os << "BillboardQuadGroup";
		case ChunkType::BillboardDisplayInfo:
			return os << "BillboardDisplayInfo";
		case ChunkType::BillboardPerspectiveInfo:
			return os << "BillboardPerspectiveInfo";
		case ChunkType::FrontendProject:
			return os << "FrontendProject";
		case ChunkType::FrontendScreen:
			return os << "FrontendScreen";
		case ChunkType::FrontendPage:
			return os << "FrontendPage";
		case ChunkType::FrontendLayer:
			return os << "FrontendLayer";
		case ChunkType::FrontendGroup:
			return os << "FrontendGroup";
		case ChunkType::FrontendMultiSprite:
			return os << "FrontendMultiSprite";
		case ChunkType::FrontendMultiText:
			return os << "FrontendMultiText";
		case ChunkType::FrontendObject:
			return os << "FrontendObject";
		case ChunkType::FrontendPolygon:
			return os << "FrontendPolygon";
		case ChunkType::FrontendStringTextBible:
			return os << "FrontendStringTextBible";
		case ChunkType::FrontendStringHardCoded:
			return os << "FrontendStringHardCoded";
		case ChunkType::FrontendTextBible:
			return os << "FrontendTextBible";
		case ChunkType::FrontendLanguage:
			return os << "FrontendLanguage";
		case ChunkType::FrontendImageResource:
			return os << "FrontendImageResource";
		case ChunkType::FrontendObjectResource:
			return os << "FrontendObjectResource";
		case ChunkType::FrontendTextStyleResource:
			return os << "FrontendTextStyleResource";
		case ChunkType::FrontendTextBibleResource:
			return os << "FrontendTextBibleResource";
		case ChunkType::Texture:
			return os << "Texture";
		case ChunkType::Image:
			return os << "Image";
		case ChunkType::ImageData:
			return os << "ImageData";
		case ChunkType::Sprite:
			return os << "Sprite";
		case ChunkType::AnimatedObjectFactory:
			return os << "AnimatedObjectFactory";
		case ChunkType::AnimatedObject:
			return os << "AnimatedObject";
		case ChunkType::AnimatedObjectAnimation:
			return os << "AnimatedObjectAnimation";
		case ChunkType::Expression:
			return os << "Expression";
		case ChunkType::ExpressionGroup:
			return os << "ExpressionGroup";
		case ChunkType::ExpressionMixer:
			return os << "ExpressionMixer";
		case ChunkType::TextureFont:
			return os << "TextureFont";
		case ChunkType::FontGlyphs:
			return os << "FontGlyphs";
		case ChunkType::SceneGraph:
			return os << "SceneGraph";
		case ChunkType::SceneGraphRoot:
			return os << "SceneGraphRoot";
		case ChunkType::SceneGraphBranch:
			return os << "SceneGraphBranch";
		case ChunkType::SceneGraphTransform:
			return os << "SceneGraphTransform";
		case ChunkType::SceneGraphVisibility:
			return os << "SceneGraphVisibility";
		case ChunkType::SceneGraphDrawable:
			return os << "SceneGraphDrawable";
		case ChunkType::SceneGraphLightGroup:
			return os << "SceneGraphLightGroup";
		case ChunkType::SceneGraphSortOrder:
			return os << "SceneGraphSortOrder";
		case ChunkType::Animation:
			return os << "Animation";
		case ChunkType::AnimationGroup:
			return os << "AnimationGroup";
		case ChunkType::AnimationGroupList:
			return os << "AnimationGroupList";
		case ChunkType::AnimationSize:
			return os << "AnimationSize";
		case ChunkType::AnimationHeader:
			return os << "AnimationHeader";
		case ChunkType::Float1Channel:
			return os << "Float1Channel";
		case ChunkType::Float2Channel:
			return os << "Float2Channel";
		case ChunkType::Vector1Channel:
			return os << "Vector1Channel";
		case ChunkType::Vector2Channel:
			return os << "Vector2Channel";
		case ChunkType::Vector3Channel:
			return os << "Vector3Channel";
		case ChunkType::QuaternionChannel:
			return os << "QuaternionChannel";
		case ChunkType::EntityChannel:
			return os << "EntityChannel";
		case ChunkType::BoolChannel:
			return os << "BoolChannel";
		case ChunkType::Color:
			return os << "Color";
		case ChunkType::IntChannel:
			return os << "IntChannel";
		case ChunkType::ChannelInterpolationMode:
			return os << "ChannelInterpolationMode";
		case ChunkType::CompressedQuaternionChannel:
			return os << "CompressedQuaternionChannel";
		case ChunkType::FrameController:
			return os << "FrameController";
		case ChunkType::FrameController2:
			return os << "FrameController2";
		case ChunkType::MultiController2:
			return os << "MultiController2";
		case ChunkType::Unknown1:
			return os << "Unknown1";
		case ChunkType::VectorOffsetList:
			return os << "VectorOffsetList";
		case ChunkType::VertexAnimKeyFrame:
			return os << "VertexAnimKeyFrame";
		case ChunkType::Fence2:
			return os << "Fence2";
		case ChunkType::RoadSegment:
			return os << "RoadSegment";
		case ChunkType::Road:
			return os << "Road";
		case ChunkType::Intersection:
			return os << "Intersection";
		case ChunkType::Locator2:
			return os << "Locator2";
		case ChunkType::TriggerVolume:
			return os << "TriggerVolume";
		case ChunkType::Spline:
			return os << "Spline";
		case ChunkType::InstanceList:
			return os << "InstanceList";
		case ChunkType::RoadDataSegment:
			return os << "RoadDataSegment";
		case ChunkType::Unknown2:
			return os << "Unknown2";
		case ChunkType::Path:
			return os << "Path";
		case ChunkType::LocatorMatrix:
			return os << "LocatorMatrix";
		case ChunkType::SurfaceTypeList:
			return os << "SurfaceTypeList";
		case ChunkType::FollowCameraData:
			return os << "FollowCameraData";
		case ChunkType::Set:
			return os << "Set";
		case ChunkType::CollisionEffect:
			return os << "CollisionEffect";
		case ChunkType::Atc:
			return os << "Atc";
		case ChunkType::BreakableObject:
			return os << "BreakableObject";
		case ChunkType::InstParticleSystem:
			return os << "InstParticleSystem";
		case ChunkType::StaticEntity:
			return os << "StaticEntity";
		case ChunkType::StaticPhysics:
			return os << "StaticPhysics";
		case ChunkType::DynamicPhysics:
			return os << "DynamicPhysics";
		case ChunkType::Intersect:
			return os << "Intersect";
		case ChunkType::Tree:
			return os << "Tree";
		case ChunkType::TreeNode:
			return os << "TreeNode";
		case ChunkType::TreeNode2:
			return os << "TreeNode2";
		case ChunkType::Fence:
			return os << "Fence";
		case ChunkType::AnimCollision:
			return os << "AnimCollision";
		case ChunkType::InstancedStaticEntity:
			return os << "InstancedStaticEntity";
		case ChunkType::InstancedStaticPhysics:
			return os << "InstancedStaticPhysics";
		case ChunkType::WorldSphere:
			return os << "WorldSphere";
		case ChunkType::Anim:
			return os << "Anim";
		case ChunkType::LensFlare:
			return os << "LensFlare";
		case ChunkType::AnimDynamicPhysics:
			return os << "AnimDynamicPhysics";
		case ChunkType::AnimDynamicPhysicsWrapper:
			return os << "AnimDynamicPhysicsWrapper";
		case ChunkType::AnimObjectWrapper:
			return os << "AnimObjectWrapper";
		case ChunkType::CollisionObject:
			return os << "CollisionObject";
		case ChunkType::CollisionVolume:
			return os << "CollisionVolume";
		case ChunkType::CollisionSphere:
			return os << "CollisionSphere";
		case ChunkType::CollisionCylinder:
			return os << "CollisionCylinder";
		case ChunkType::CollisionOBBoxVolume:
			return os << "CollisionOBBoxVolume";
		case ChunkType::CollisionWallVolume:
			return os << "CollisionWallVolume";
		case ChunkType::CollisionBBoxVolume:
			return os << "CollisionBBoxVolume";
		case ChunkType::CollisionVector:
			return os << "CollisionVector";
		case ChunkType::CollisionVolumeOwner:
			return os << "CollisionVolumeOwner";
		case ChunkType::CollisionVolumeOwnerName:
			return os << "CollisionVolumeOwnerName";
		case ChunkType::CollisionObjectAttribute:
			return os << "CollisionObjectAttribute";
		case ChunkType::PhysicsObject:
			return os << "PhysicsObject";
		case ChunkType::PhysicsInertiaMatrix:
			return os << "PhysicsInertiaMatrix";
		case ChunkType::PhysicsVector:
			return os << "PhysicsVector";
		case ChunkType::PhysicsJoint:
			return os << "PhysicsJoint";
		case ChunkType::StaticPropData:
			return os << "StaticPropData";
		case ChunkType::StaticPropStateData:
			return os << "StaticPropStateData";
		case ChunkType::StaticPropVisibilityData:
			return os << "StaticPropVisibilityData";
		case ChunkType::StaticPropFrameControllerData:
			return os << "StaticPropFrameControllerData";
		case ChunkType::StaticPropEventData:
			return os << "StaticPropEventData";
		case ChunkType::StaticPropCallbackData:
			return os << "StaticPropCallbackData";
		case ChunkType::P3DZRoot:
			return os << "P3DZRoot";
		case ChunkType::P3DRoot:
			return os << "P3DRoot";
	};
	return os << "Unknown " << std::hex << std::showbase << static_cast<uint32_t>(chunktype)
	          << std::dec << std::noshowbase;
}

} // namespace Donut::P3D
