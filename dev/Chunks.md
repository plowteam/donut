# Chunks (97 / 182)

## Animation `0x121000`
|Name|Type|
|--|--|
|`version`|`u32`|
|`name`|`string`|
|`type`|`string[4]`|
|`numFrames`|`float`|
|`frameRate`|`float`|
|`looping`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`groupList`|`AnimationGroupList`|
|`size`|`AnimationSize`|

## AnimationSize `0x121004`
|Name|Type|
|--|--|
|`version`|`u32`|
|`PC`|`u32`|
|`PS2`|`u32`|
|`XBOX`|`u32`|
|`GC`|`u32`|

## AnimationGroupList `0x121002`
|Name|Type|
|--|--|
|`version`|`u32`|
|`numGroups`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`groups`|`AnimationGroup[]`|

## AnimationGroup `0x121001`
|Name|Type|
|--|--|
|`version`|`u32`|
|`name`|`string`|
|`groupId`|`u32`|
|`numChannels`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`vector2Channels`|`Vector2Channel[]`|
|`vector3Channels`|`Vector3Channel[]`|
|`quaternionChannels`|`QuaternionChannel[]`|
|`compressedQuaternionChannels`|`CompressedQuaternionChannel[]`|

## ChannelInterpolationMode `0x121110`
|Name|Type|
|--|--|
|`version`|`u32`|
|`mode`|`u32`|

## Vector2Channel `0x121103`
|Name|Type|
|--|--|
|`version`|`u32`|
|`param`|`string[4]`|
|`mapping`|`u16`|
|`constants`|`vec3`|
|`numFrames`|`u32`|
|`frames`|`u16[numFrames]`|
|`values`|`vec2[numFrames]`|

### Children
|Name|Chunk|
|--|--|
|`interpolationMode`|`ChannelInterpolationMode`|

## Vector3Channel `0x121104`
|Name|Type|
|--|--|
|`version`|`u32`|
|`param`|`string[4]`|
|`numFrames`|`u32`|
|`frames`|`u16[numFrames]`|
|`values`|`vec3[numFrames]`|

### Children
|Name|Chunk|
|--|--|
|`interpolationMode`|`ChannelInterpolationMode`|

## QuaternionChannel `0x121105`
|Name|Type|
|--|--|
|`version`|`u32`|
|`param`|`string[4]`|
|`numFrames`|`u32`|
|`frames`|`u16[numFrames]`|
|`values`|`quat[numFrames]`|

### Children
|Name|Chunk|
|--|--|
|`interpolationMode`|`ChannelInterpolationMode`|

## CompressedQuaternionChannel `0x121111`
|Name|Type|
|--|--|
|`version`|`u32`|
|`param`|`string[4]`|
|`numFrames`|`u32`|
|`frames`|`u16[numFrames]`|
|`values`|`u64[numFrames]`|

### Children
|Name|Chunk|
|--|--|
|`interpolationMode`|`ChannelInterpolationMode`|

## Mesh `0x10000`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`numPrimGroups`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`primitiveGroups`|`PrimitiveGroup[]`|

## PolySkin `0x10001`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`skeletonName`|`string`|
|`numPrimGroups`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`primitiveGroups`|`PrimitiveGroup[]`|
|`boundingBox`|`BoundingBox`|
|`boundingSphere`|`BoundingSphere`|

## BoundingBox `0x10003`
|Name|Type|
|--|--|
|`min`|`vec3`|
|`max`|`vec3`|

## BoundingSphere `0x10004`
|Name|Type|
|--|--|
|`centre`|`vec3`|
|`radius`|`float`|

## PrimitiveGroup `0x10002`
|Name|Type|
|--|--|
|`version`|`u32`|
|`shaderName`|`string`|
|`primType`|`u32`|
|`hasDataFlags`|`u32`|
|`numVerts`|`u32`|
|`numIndices`|`u32`|
|`numMatrices`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`vertices`|`PositionList<vec3>[u32]`|
|`indices`|`IndexList<u32>[u32]`|
|`normals`|`NormalList<vec3>[u32]`|
|`uvs`|`UVList<vec2>[u32][u32]`|
|`matrixList`|`MatrixList<u32>[u32]`|
|`matrixPalette`|`MatrixPalette<u32>[u32]`|
|`weightList`|`WeightList<vec3>[u32]`|
|`colors`|`ColorList<u32>[u32]`|

## PositionList `0x10005`
|Name|Type|
|--|--|
|`size`|`u32`|
|`positions`|`vec3[size]`|

## IndexList `0x1000A`
|Name|Type|
|--|--|
|`size`|`u32`|
|`indices`|`u32[size]`|

## NormalList `0x10006`
|Name|Type|
|--|--|
|`size`|`u32`|
|`normals`|`vec3[size]`|

## UVList `0x10007`
|Name|Type|
|--|--|
|`size`|`u32`|
|`channel`|`u32`|
|`uvs`|`vec2[size]`|

## MatrixList `0x1000B`
|Name|Type|
|--|--|
|`size`|`u32`|
|`uvs`|`u32[size]`|

## MatrixPalette `0x1000D`
|Name|Type|
|--|--|
|`size`|`u32`|
|`uvs`|`u32[size]`|

## WeightList `0x1000C`
|Name|Type|
|--|--|
|`size`|`u32`|
|`uvs`|`vec3[size]`|

## ColorList `0x10008`
|Name|Type|
|--|--|
|`size`|`u32`|
|`uvs`|`u32[size]`|

## Skeleton `0x4500`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`numJoints`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`joints`|`SkeletonJoint[]`|

## SkeletonJoint `0x4501`
|Name|Type|
|--|--|
|`name`|`string`|
|`parent`|`u32`|
|`dof`|`s32`|
|`freeAxis`|`s32`|
|`primaryAxis`|`s32`|
|`secondaryAxis`|`s32`|
|`twistAxis`|`s32`|
|`restPose`|`mat4`|

### Children
|Name|Chunk|
|--|--|
|`mirrorMap`|`SkeletonJointMirrorMap`|
|`bonePreserve`|`SkeletonJointBonePreserve`|

## SkeletonJointMirrorMap `0x4503`
|Name|Type|
|--|--|
|`jointIndex`|`u32`|
|`axis`|`vec3`|

## SkeletonJointBonePreserve `0x4504`
|Name|Type|
|--|--|
|`depth`|`u32`|

## StaticEntity `0x3F00000`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`renderOrder`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`mesh`|`Mesh`|

## StaticPhysics `0x3F00001`
|Name|Type|
|--|--|
|`name`|`string`|
|`todo`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`collisionObject`|`CollisionObject`|

## InstancedStaticPhysics `0x3F0000A`
|Name|Type|
|--|--|
|`name`|`string`|
|`todo`|`u32`|
|`renderOrder`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`meshes`|`Mesh[]`|
|`instanceList`|`InstanceList`|

## DynamicPhysics `0x3F00002`
|Name|Type|
|--|--|
|`name`|`string`|
|`todo`|`u32`|
|`renderOrder`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`meshes`|`Mesh[]`|
|`instanceList`|`InstanceList`|

## AnimDynamicPhysics `0x3F0000E`
|Name|Type|
|--|--|
|`name`|`string`|
|`todo`|`u32`|
|`renderOrder`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`animObjectWrapper`|`AnimObjectWrapper`|
|`instanceList`|`InstanceList`|

## AnimObjectWrapper `0x3F00010`
|Name|Type|
|--|--|
|`name`|`string`|
|`todo`|`u16`|

### Children
|Name|Chunk|
|--|--|
|`compositeDrawables`|`CompositeDrawable[]`|
|`skeletons`|`Skeleton[]`|
|`meshes`|`Mesh[]`|
|`animations`|`Animation[]`|

## InstanceList `0x3000008`
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`sceneGraph`|`SceneGraph`|

## SceneGraph `0x120100`
|Name|Type|
|--|--|
|`name`|`string`|
|`todo`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`root`|`SceneGraphRoot`|

## SceneGraphRoot `0x120101`
|Name|Type|
|--|--|

### Children
|Name|Chunk|
|--|--|
|`branch`|`SceneGraphBranch`|

## SceneGraphBranch `0x120102`
|Name|Type|
|--|--|
|`name`|`string`|
|`numChildren`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`children`|`SceneGraphTransform[]`|

## SceneGraphTransform `0x120103`
|Name|Type|
|--|--|
|`name`|`string`|
|`numChildren`|`u32`|
|`transform`|`mat4`|

### Children
|Name|Chunk|
|--|--|
|`children`|`SceneGraphTransform[]`|
|`drawables`|`SceneGraphDrawable[]`|

## SceneGraphDrawable `0x120107`
|Name|Type|
|--|--|
|`name`|`string`|
|`drawableName`|`string`|
|`translucent`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`sortOrder`|`SceneGraphSortOrder<float>`|

## SceneGraphSortOrder `0x12010A`
|Name|Type|
|--|--|
|`value`|`float`|

## Shader `0x11000`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`pddiShaderName`|`string`|
|`isTrans`|`u32`|
|`vertexNeeds`|`u32`|
|`vertexMask`|`u32`|
|`numParams`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`textureParams`|`ShaderTextureParam[]`|
|`integerParams`|`ShaderIntParam[]`|
|`floatParams`|`ShaderFloatParam[]`|
|`colorParams`|`ShaderColorParam[]`|

## ShaderTextureParam `0x11002`
|Name|Type|
|--|--|
|`key`|`string[4]`|
|`value`|`string`|

## ShaderIntParam `0x11003`
|Name|Type|
|--|--|
|`key`|`string[4]`|
|`value`|`s32`|

## ShaderFloatParam `0x11004`
|Name|Type|
|--|--|
|`key`|`string[4]`|
|`value`|`float`|

## ShaderColorParam `0x11005`
|Name|Type|
|--|--|
|`key`|`string[4]`|
|`r`|`u8`|
|`g`|`u8`|
|`b`|`u8`|
|`a`|`u8`|

## CompositeDrawable `0x4512`
|Name|Type|
|--|--|
|`name`|`string`|
|`skeletonName`|`string`|

### Children
|Name|Chunk|
|--|--|
|`propList`|`CompositeDrawablePropList`|

## CompositeDrawablePropList `0x4514`
|Name|Type|
|--|--|
|`numElements`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`props`|`CompositeDrawableProp[]`|

## CompositeDrawableProp `0x4516`
|Name|Type|
|--|--|
|`name`|`string`|
|`isTrans`|`u32`|
|`skeletonJoint`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`sortOrder`|`CompositeDrawableSortOrder<float>`|

## CompositeDrawableSortOrder `0x4519`
|Name|Type|
|--|--|
|`value`|`float`|

## Intersect `0x3F00003`
|Name|Type|
|--|--|
|`indices`|`u32[u32]`|
|`positions`|`vec3[u32]`|
|`normals`|`vec3[u32]`|

### Children
|Name|Chunk|
|--|--|
|`bounds`|`BoundingBox`|

## WorldSphere `0x3F0000B`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`meshCount`|`u32`|
|`billboardCount`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`animation`|`Animation`|
|`skeletons`|`Skeleton[]`|
|`billboards`|`BillboardQuadGroup[]`|
|`meshes`|`Mesh[]`|
|`compositeDrawable`|`CompositeDrawable`|
|`lensFlare`|`LensFlare`|

## LensFlare `0x3F0000D`
|Name|Type|
|--|--|
|`name`|`string`|
|`billboardCount`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`billboards`|`BillboardQuadGroup[]`|
|`compositeDrawable`|`CompositeDrawable`|

## BillboardQuad `0x17001`
|Name|Type|
|--|--|
|`version`|`u32`|
|`name`|`string`|
|`mode`|`string[4]`|
|`translation`|`vec3`|
|`color`|`u32`|
|`uv0`|`vec2`|
|`uv1`|`vec2`|
|`uv2`|`vec2`|
|`uv3`|`vec2`|
|`width`|`float`|
|`height`|`float`|
|`distance`|`float`|
|`uvOffset`|`vec2`|

### Children
|Name|Chunk|
|--|--|
|`displayInfo`|`BillboardDisplayInfo`|
|`perspectiveInfo`|`BillboardPerspectiveInfo`|

## BillboardQuadGroup `0x17002`
|Name|Type|
|--|--|
|`version`|`u32`|
|`name`|`string`|
|`shader`|`string`|
|`zTest`|`u32`|
|`zWrite`|`u32`|
|`fog`|`u32`|
|`quadCount`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`quads`|`BillboardQuad[]`|

## BillboardDisplayInfo `0x17003`
|Name|Type|
|--|--|
|`version`|`u32`|
|`rotation`|`quat`|
|`cutOffMode`|`string[4]`|
|`uvOffsetRange`|`vec2`|
|`sourceRange`|`float`|
|`edgeRange`|`float`|

## BillboardPerspectiveInfo `0x17004`
|Name|Type|
|--|--|
|`version`|`u32`|
|`value`|`u32`|

## Texture `0x19000`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`width`|`u32`|
|`height`|`u32`|
|`bpp`|`u32`|
|`alphaDepth`|`u32`|
|`numMipMaps`|`u32`|
|`textureType`|`u32`|
|`usage`|`u32`|
|`priority`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`image`|`Image`|

## Image `0x19001`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`width`|`u32`|
|`height`|`u32`|
|`bpp`|`u32`|
|`palettized`|`u32`|
|`hasAlpha`|`u32`|
|`format`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`data`|`ImageData<u8>[u32]`|

## ImageData `0x19002`
|Name|Type|
|--|--|
|`size`|`u32`|
|`data`|`u8[size]`|

## TextureFont `0x22000`
|Name|Type|
|--|--|
|`version`|`u32`|
|`name`|`string`|
|`shader`|`string`|
|`size`|`float`|
|`width`|`float`|
|`height`|`float`|
|`baseLine`|`float`|
|`numTextures`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`textures`|`Texture[]`|
|`glyphs`|`FontGlyphs<FontGlyph>[u32]`|

## FontGlyphs `0x22001`
|Name|Type|
|--|--|
|`size`|`u32`|
|`glyphs`|`FontGlyph[size]`|

## Sprite `0x19005`
|Name|Type|
|--|--|
|`name`|`string`|
|`nativeX`|`u32`|
|`nativeY`|`u32`|
|`shader`|`string`|
|`width`|`u32`|
|`height`|`u32`|
|`imageCount`|`u32`|
|`blitBorder`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`images`|`Image[]`|

## FrontendScreen `0x18001`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`numPages`|`u32`|
|`pageNames`|`string[numPages]`|

## FrontendProject `0x18000`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`resX`|`u32`|
|`resY`|`u32`|
|`platform`|`string`|
|`pagePath`|`string`|
|`resourcePath`|`string`|
|`screenPath`|`string`|

### Children
|Name|Chunk|
|--|--|
|`pages`|`FrontendPage[]`|
|`screens`|`FrontendScreen[]`|

## FrontendPage `0x18002`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`resX`|`u32`|
|`resY`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`layers`|`FrontendLayer[]`|
|`imageResources`|`FrontendImageResource[]`|

## FrontendLayer `0x18003`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`visible`|`u32`|
|`editable`|`u32`|
|`alpha`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`groups`|`FrontendGroup[]`|
|`multiSprites`|`FrontendMultiSprite[]`|
|`multiTexts`|`FrontendMultiText[]`|
|`objects`|`FrontendObject[]`|
|`polygons`|`FrontendPolygon[]`|

## FrontendGroup `0x18004`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`alpha`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`children`|`FrontendGroup[]`|
|`multiSprites`|`FrontendMultiSprite[]`|
|`multiTexts`|`FrontendMultiText[]`|
|`polygons`|`FrontendPolygon[]`|

## FrontendMultiSprite `0x18006`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`positionX`|`s32`|
|`positionY`|`s32`|
|`dimensionX`|`u32`|
|`dimensionY`|`u32`|
|`alignX`|`u32`|
|`alignY`|`u32`|
|`color`|`u32`|
|`translucent`|`u32`|
|`rotation`|`float`|
|`numImages`|`u32`|
|`imageNames`|`string[numImages]`|

## FrontendMultiText `0x18007`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`positionX`|`s32`|
|`positionY`|`s32`|
|`dimensionX`|`u32`|
|`dimensionY`|`u32`|
|`alignX`|`u32`|
|`alignY`|`u32`|
|`color`|`u32`|
|`translucent`|`u32`|
|`rotation`|`float`|
|`fontName`|`string`|
|`shadowEnabled`|`u8`|
|`shadowColor`|`u32`|
|`shadowOffsetX`|`s32`|
|`shadowOffsetY`|`s32`|
|`current`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`textBibles`|`FrontendStringTextBible[]`|

## FrontendStringTextBible `0x1800B`
|Name|Type|
|--|--|
|`name`|`string`|
|`key`|`string`|

## FrontendObject `0x18008`
|Name|Type|
|--|--|
|`name`|`string`|

## FrontendPolygon `0x18009`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`translucent`|`u32`|
|`numPoints`|`u32`|
|`points`|`vec3[numPoints]`|
|`colors`|`u32[numPoints]`|

## FrontendImageResource `0x18100`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`filepath`|`string`|

## Locator2 `0x3000005`
|Name|Type|
|--|--|
|`name`|`string`|
|`type`|`u32`|
|`dataSize`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`triggers`|`TriggerVolume[]`|

## TriggerVolume `0x3000006`
|Name|Type|
|--|--|
|`name`|`string`|
|`isRect`|`u32`|
|`bounds`|`vec3`|
|`transform`|`mat4`|

## Camera `0x2200`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`fov`|`float`|
|`aspectRatio`|`float`|
|`nearClip`|`float`|
|`farClip`|`float`|
|`position`|`vec3`|
|`forward`|`vec3`|
|`up`|`vec3`|

## MultiController `0x48A0`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`length`|`float`|
|`frameRate`|`float`|
|`numTracks`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`tracks`|`MultiControllerTracks`|

## MultiControllerTracks `0x48A1`
|Name|Type|
|--|--|
|`numTracks`|`u32`|
|`trackNames`|`string[numTracks]`|
|`trackStartTimes`|`float[numTracks]`|
|`trackEndTimes`|`float[numTracks]`|
|`trackScales`|`float[numTracks]`|

## CollisionObject `0x7010000`
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`materialName`|`string`|
|`numSubObjects`|`u32`|
|`numVolumeOwners`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`volumeOwners`|`CollisionVolumeOwner[]`|
|`volume`|`CollisionVolume`|
|`attribute`|`CollisionObjectAttribute`|

## CollisionVolume `0x7010001`
|Name|Type|
|--|--|
|`objectRefIndex`|`u32`|
|`ownerIndex`|`s32`|
|`numSubVolumes`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`subVolumes`|`CollisionVolume[]`|
|`bBox`|`CollisionBBoxVolume`|
|`obBox`|`CollisionOBBoxVolume`|
|`sphere`|`CollisionSphere`|
|`cylinder`|`CollisionCylinder`|

## CollisionSphere `0x7010002`
|Name|Type|
|--|--|
|`radius`|`float`|

### Children
|Name|Chunk|
|--|--|
|`vectors`|`CollisionVector<vec3>[]`|

## CollisionCylinder `0x7010003`
|Name|Type|
|--|--|
|`radius`|`float`|
|`length`|`float`|
|`flatEnd`|`u16`|

### Children
|Name|Chunk|
|--|--|
|`vectors`|`CollisionVector<vec3>[]`|

## CollisionOBBoxVolume `0x7010004`
|Name|Type|
|--|--|
|`halfExtents`|`vec3`|

### Children
|Name|Chunk|
|--|--|
|`vectors`|`CollisionVector<vec3>[]`|

## CollisionBBoxVolume `0x7010006`
|Name|Type|
|--|--|
|`nothing`|`u32`|

## CollisionVector `0x7010007`
|Name|Type|
|--|--|
|`value`|`vec3`|

## CollisionVolumeOwner `0x7010021`
|Name|Type|
|--|--|
|`numNames`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`names`|`CollisionVolumeOwnerName[]`|

## CollisionVolumeOwnerName `0x7010022`
|Name|Type|
|--|--|
|`name`|`string`|

## CollisionObjectAttribute `0x7010023`
|Name|Type|
|--|--|
|`static`|`u16`|
|`defaultArea`|`u32`|
|`canRoll`|`u16`|
|`canSlide`|`u16`|
|`canSpin`|`u16`|
|`canBounce`|`u16`|
|`todo1`|`u32`|
|`todo2`|`u32`|
|`todo3`|`u32`|

## FenceWrapper `0x3F00007`
|Name|Type|
|--|--|

### Children
|Name|Chunk|
|--|--|
|`fence`|`Fence`|

## Fence `0x3000000`
|Name|Type|
|--|--|
|`start`|`vec3`|
|`end`|`vec3`|
|`normal`|`vec3`|

## Set `0x3000110`
|Name|Type|
|--|--|
|`name`|`string`|
|`numTextures`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`textures`|`Texture[]`|

## Path `0x300000B`
|Name|Type|
|--|--|
|`numPoints`|`u32`|
|`points`|`vec3[numPoints]`|

## Intersection `0x3000004`
|Name|Type|
|--|--|
|`name`|`string`|
|`position`|`vec3`|
|`radius`|`float`|
|`trafficBehaviour`|`u32`|

## RoadDataSegment `0x3000009`
|Name|Type|
|--|--|
|`name`|`string`|
|`todo0`|`u32`|
|`lanes`|`u32`|
|`todo1`|`u32`|
|`position0`|`vec3`|
|`position1`|`vec3`|
|`position2`|`vec3`|

## Road `0x3000003`
|Name|Type|
|--|--|
|`name`|`string`|
|`todo0`|`u32`|
|`startIntersection`|`string`|
|`endIntersection`|`string`|
|`maxCars`|`u32`|
|`todo1`|`u8`|
|`todo2`|`u8`|
|`noReset`|`u8`|
|`todo3`|`u8`|

## GameAttr `0x12000`
|Name|Type|
|--|--|
|`version`|`u32`|
|`name`|`string`|
|`numParams`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`params`|`GameAttrIntParam[]`|

## GameAttrIntParam `0x12001`
|Name|Type|
|--|--|
|`name`|`string`|
|`value`|`u32`|

## History `0x7000`
|Name|Type|
|--|--|
|`numLines`|`u32`|
|`lines`|`string[u32]`|

# TODO Chunks (85 / 182)
#### LightGroup `0x2380`
#### CompositeDrawableSkinList `0x4513`
#### CompositeDrawableSkin `0x4515`
#### CompositeDrawableEffectList `0x4517`
#### CompositeDrawableEffect `0x4518`
#### ExportInfo `0x7030`
#### ExportInfoNamedString `0x7031`
#### ExportInfoNamedInteger `0x7032`
#### OffsetList `0x1000E`
#### PackedNormalList `0x10010`
#### VertexShader `0x10011`
#### DrawShadow `0x10017`
#### ExpressionOffsets `0x10018`
#### Light `0x13000`
#### LightDirection `0x13001`
#### LightPosition `0x13002`
#### LightShadow `0x13004`
#### Todo0 `0x13008`
#### Locator `0x14000`
#### ParticleSystemFactory `0x15800`
#### ParticleSystem `0x15801`
#### BaseEmitter `0x15805`
#### SpriteEmitter `0x15806`
#### ParticleAnimation `0x15808`
#### EmitterAnimation `0x15809`
#### GeneratorAnimation `0x1580A`
#### ParticleInstancingInfo `0x1580B`
#### FrontendStringHardCoded `0x1800C`
#### FrontendTextBible `0x1800D`
#### FrontendLanguage `0x1800E`
#### FrontendObjectResource `0x18101`
#### FrontendTextStyleResource `0x18104`
#### FrontendTextBibleResource `0x18105`
#### AnimatedObjectFactory `0x20000`
#### AnimatedObject `0x20001`
#### AnimatedObjectAnimation `0x20002`
#### Expression `0x21000`
#### ExpressionGroup `0x21001`
#### ExpressionMixer `0x21002`
#### SceneGraphVisibility `0x120104`
#### SceneGraphLightGroup `0x120109`
#### AnimationHeader `0x121006`
#### Float1Channel `0x121100`
#### Float2Channel `0x121101`
#### Vector1Channel `0x121102`
#### EntityChannel `0x121107`
#### BoolChannel `0x121108`
#### Color `0x121109`
#### IntChannel `0x12110E`
#### FrameController `0x121200`
#### FrameController2 `0x121201`
#### MultiController2 `0x121202`
#### Todo1 `0x121203`
#### VectorOffsetList `0x121301`
#### VertexAnimKeyFrame `0x121304`
#### RoadSegment `0x3000002`
#### Spline `0x3000007`
#### Todo2 `0x300000A`
#### LocatorMatrix `0x300000C`
#### SurfaceTypeList `0x300000E`
#### FollowCameraData `0x3000100`
#### CollisionEffect `0x3000600`
#### Atc `0x3000602`
#### BreakableObject `0x3001000`
#### InstParticleSystem `0x3001001`
#### Tree `0x3F00004`
#### TreeNode `0x3F00005`
#### TreeNode2 `0x3F00006`
#### AnimCollision `0x3F00008`
#### InstancedStaticEntity `0x3F00009`
#### Anim `0x3F0000C`
#### AnimDynamicPhysicsWrapper `0x3F0000F`
#### CollisionWallVolume `0x7010005`
#### PhysicsObject `0x7011000`
#### PhysicsInertiaMatrix `0x7011001`
#### PhysicsVector `0x7011002`
#### PhysicsJoint `0x7011020`
#### StaticPropData `0x8020000`
#### StaticPropStateData `0x8020001`
#### StaticPropVisibilityData `0x8020002`
#### StaticPropFrameControllerData `0x8020003`
#### StaticPropEventData `0x8020004`
#### StaticPropCallbackData `0x8020005`
#### P3DZRoot `0x5A443350`
#### P3DRoot `0xFF443350`

