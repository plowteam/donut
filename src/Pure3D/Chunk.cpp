#include <Pure3D/Chunk.h>

namespace Donut::Pure3D {

void Chunk::Read(const File& file) {
    std::uint32_t dataSize, totalSize;

    file.Read<ChunkType>(&_type);
    file.Read<uint32_t>(&dataSize);
    file.Read<uint32_t>(&totalSize);

    // read the data
    _data.resize(dataSize - 12);
    file.ReadBytes(_data.data(), dataSize - 12);

    readChildren(file, totalSize - dataSize);
}

void Chunk::readChildren(const File& file, std::uint32_t size) {
    if (size <= 0)
        return;

    uint32_t endPos = file.Position() + size;
    while (file.Position() < endPos) {
        _children.push_back(std::make_unique<Chunk>());
        _children.back()->Read(file);
    }
}

std::ostream& operator<<(std::ostream& os, ChunkType chunktype) {
    switch (chunktype) {
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
    case ChunkType::ColourList:
        return os << "ColourList";
    case ChunkType::IndexList:
        return os << "IndexList";
    case ChunkType::MatrixList:
        return os << "MatrixList";
    case ChunkType::WeightList:
        return os << "WeightList";
    case ChunkType::MatrixPalette:
        return os << "MatrixPalette";
    case ChunkType::PackedNormalList:
        return os << "PackedNormalList";
    case ChunkType::VertexShader:
        return os << "VertexShader";
    case ChunkType::Shader:
        return os << "Shader";
    case ChunkType::ShaderTextureParam:
        return os << "ShaderTextureParam";
    case ChunkType::ShaderIntParam:
        return os << "ShaderIntParam";
    case ChunkType::ShaderFloatParam:
        return os << "ShaderFloatParam";
    case ChunkType::ShaderColourParam:
        return os << "ShaderColourParam";
    case ChunkType::GameAttr:
        return os << "GameAttr";
    case ChunkType::Light:
        return os << "Light";
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
    case ChunkType::ParticleInstancingInfo:
        return os << "ParticleInstancingInfo";
    case ChunkType::LensFlareGroup:
        return os << "LensFlareGroup";
    case ChunkType::BillboardQuad:
        return os << "BillboardQuad";
    case ChunkType::BillboardQuadGroup:
        return os << "BillboardQuadGroup";
    case ChunkType::BillboardDisplayInfo:
        return os << "BillboardDisplayInfo";
    case ChunkType::BillboardPerspectiveInfo:
        return os << "BillboardPerspectiveInfo";
    case ChunkType::TextBible:
        return os << "TextBible";
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
    case ChunkType::Expression:
        return os << "Expression";
    case ChunkType::ExpressionGroup:
        return os << "ExpressionGroup";
    case ChunkType::ExpressionMixer:
        return os << "ExpressionMixer";
    case ChunkType::TextureFont:
        return os << "TextureFont";
    case ChunkType::ImageFont:
        return os << "ImageFont";
    case ChunkType::Scenegraph:
        return os << "Scenegraph";
    case ChunkType::Animation:
        return os << "Animation";
    case ChunkType::AnimationGroup:
        return os << "AnimationGroup";
    case ChunkType::AnimationGroupList:
        return os << "AnimationGroupList";
    case ChunkType::AnimationSize:
        return os << "AnimationSize";
    case ChunkType::Vector1Channel:
        return os << "Vector1Channel";
    case ChunkType::Vector2Channel:
        return os << "Vector2Channel";
    case ChunkType::Vector3Channel:
        return os << "Vector3Channel";
    case ChunkType::QuaternionChannel:
        return os << "QuaternionChannel";
    case ChunkType::ChannelInterpolationMode:
        return os << "ChannelInterpolationMode";
    case ChunkType::CompressedQuaternionChannel:
        return os << "CompressedQuaternionChannel";
    case ChunkType::FrameController:
        return os << "FrameController";
    case ChunkType::VertexAnimKey:
        return os << "VertexAnimKey";
    case ChunkType::Intersection:
        return os << "Intersection";
    case ChunkType::RoadDataSegment:
        return os << "RoadDataSegment";
    case ChunkType::CarCameraData:
        return os << "CarCameraData";
    case ChunkType::Set:
        return os << "Set";
    case ChunkType::PhysicsObject:
        return os << "PhysicsObject";
    case ChunkType::PhysicsInertiaMatrix:
        return os << "PhysicsInertiaMatrix";
    case ChunkType::PhysicsVector:
        return os << "PhysicsVector";
    case ChunkType::PhysicsJoint:
        return os << "PhysicsJoint";
    case ChunkType::StatePropData:
        return os << "StatePropData";
    case ChunkType::P3DRoot:
        return os << "P3DRoot";
    };
    return os << "Unknown " << std::hex << std::showbase << static_cast<std::uint32_t>(chunktype) << std::dec << std::noshowbase;
}

} // namespace Donut::Pure3D
