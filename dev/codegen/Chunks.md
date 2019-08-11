## Animation
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

## AnimationGroupList
|Name|Type|
|--|--|
|`version`|`u32`|
|`numGroups`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`groups`|`AnimationGroup[]`|

## AnimationGroup
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

## Vector2Channel
|Name|Type|
|--|--|
|`version`|`u32`|
|`param`|`string[4]`|
|`mapping`|`u16`|
|`constants`|`vec3`|
|`numFrames`|`u32`|
|`frames`|`u16[numFrames][]`|
|`values`|`vec2[numFrames][]`|

## Vector3Channel
|Name|Type|
|--|--|
|`version`|`u32`|
|`param`|`string[4]`|
|`numFrames`|`u32`|
|`frames`|`u16[numFrames][]`|
|`values`|`vec3[numFrames][]`|

## QuaternionChannel
|Name|Type|
|--|--|
|`version`|`u32`|
|`param`|`string[4]`|
|`numFrames`|`u32`|
|`frames`|`u16[numFrames][]`|
|`values`|`quat[numFrames][]`|

## CompressedQuaternionChannel
|Name|Type|
|--|--|
|`version`|`u32`|
|`param`|`string[4]`|
|`numFrames`|`u32`|
|`frames`|`u16[numFrames][]`|
|`values`|`u64[numFrames][]`|

## Mesh
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`numPrimGroups`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`primitiveGroups`|`PrimitiveGroup[]`|

## PolySkin
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

## BoundingBox
|Name|Type|
|--|--|
|`min`|`vec3`|
|`max`|`vec3`|

## BoundingSphere
|Name|Type|
|--|--|
|`centre`|`vec3`|
|`radius`|`float`|

## PrimitiveGroup
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
|`vertices`|`PositionList[]`|
|`indices`|`IndexList[]`|
|`normals`|`NormalList[]`|
|`uvs`|`UVList[][]`|
|`matrixList`|`MatrixList[]`|
|`weightList`|`WeightList[]`|
|`matrixPalette`|`MatrixPalette[]`|
|`colors`|`ColorList[]`|

## Skeleton
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`numJoints`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`joints`|`SkeletonJoint[]`|

## SkeletonJoint
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

## StaticEntity
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`renderOrder`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`mesh`|`Mesh`|

## StaticPhysics
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`collisionObject`|`CollisionObject`|

## InstancedStaticPhysics
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`meshes`|`Mesh[]`|
|`instanceList`|`InstanceList`|

## DynamicPhysics
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`meshes`|`Mesh[]`|
|`instanceList`|`InstanceList`|

## AnimDynamicPhysics
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`animObjectWrapper`|`AnimObjectWrapper`|
|`instanceList`|`InstanceList`|

## AnimObjectWrapper
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`compositeDrawables`|`CompositeDrawable[]`|
|`skeletons`|`Skeleton[]`|
|`meshes`|`Mesh[]`|
|`animations`|`Animation[]`|

## InstanceList
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`sceneGraph`|`SceneGraph`|

## SceneGraph
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`root`|`SceneGraphRoot`|

## SceneGraphRoot
|Name|Type|
|--|--|

### Children
|Name|Chunk|
|--|--|
|`branch`|`SceneGraphBranch`|

## SceneGraphBranch
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`children`|`SceneGraphTransform[]`|

## SceneGraphTransform
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

## SceneGraphDrawable
|Name|Type|
|--|--|
|`name`|`string`|

### Children
|Name|Chunk|
|--|--|
|`sortOrder`|`SceneGraphSortOrder<float>`|

## Shader
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

## ShaderTextureParam
|Name|Type|
|--|--|
|`key`|`string[4]`|
|`value`|`string`|

## ShaderIntParam
|Name|Type|
|--|--|
|`key`|`string[4]`|
|`value`|`s32`|

## ShaderFloatParam
|Name|Type|
|--|--|
|`key`|`string[4]`|
|`value`|`float`|

## ShaderColorParam
|Name|Type|
|--|--|
|`key`|`string[4]`|
|`r`|`u8`|
|`g`|`u8`|
|`b`|`u8`|
|`a`|`u8`|

## CompositeDrawable
|Name|Type|
|--|--|
|`name`|`string`|
|`skeletonName`|`string`|

### Children
|Name|Chunk|
|--|--|
|`propList`|`CompositeDrawablePropList`|

## CompositeDrawablePropList
|Name|Type|
|--|--|
|`numElements`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`props`|`CompositeDrawableProp[]`|

## CompositeDrawableProp
|Name|Type|
|--|--|
|`name`|`string`|
|`isTrans`|`u32`|
|`skeletonJoint`|`u32`|

## Intersect
|Name|Type|
|--|--|
|`indices`|`u32[]`|
|`positions`|`vec3[]`|
|`normals`|`vec3[]`|

### Children
|Name|Chunk|
|--|--|
|`bounds`|`BoundingBox`|

## WorldSphere
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`meshCount`|`u32`|
|`billboardCount`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`meshes`|`Mesh[]`|

## BillboardQuad
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

## BillboardQuadGroup
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

## Texture
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

## Image
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
|`data`|`ImageData[]`|

## TextureFont
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
|`glyphs`|`FontGlyphs[]`|

## Sprite
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

## FrontendScreen
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`numPages`|`u32`|
|`pageNames`|`string[numPages][]`|

## FrontendProject
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

## FrontendPage
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

## FrontendLayer
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

## FrontendGroup
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

## FrontendMultiSprite
|Name|Type|
|--|--|
|`name`|`string`|

## FrontendMultiText
|Name|Type|
|--|--|
|`name`|`string`|

## FrontendObject
|Name|Type|
|--|--|
|`name`|`string`|

## FrontendPolygon
|Name|Type|
|--|--|
|`name`|`string`|

## FrontendImageResource
|Name|Type|
|--|--|
|`name`|`string`|
|`version`|`u32`|
|`filepath`|`string`|

## Locator2
|Name|Type|
|--|--|
|`name`|`string`|
|`type`|`u32`|
|`dataSize`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`triggers`|`TriggerVolume[]`|

## TriggerVolume
|Name|Type|
|--|--|
|`name`|`string`|

## Camera
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

## MultiController
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

## MultiControllerTracks
|Name|Type|
|--|--|

## CollisionObject
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

## CollisionVolume
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

## CollisionSphere
|Name|Type|
|--|--|
|`radius`|`float`|

### Children
|Name|Chunk|
|--|--|
|`vectors`|`CollisionVector<vec3>[]`|

## CollisionCylinder
|Name|Type|
|--|--|
|`radius`|`float`|
|`length`|`float`|
|`flatEnd`|`u16`|

### Children
|Name|Chunk|
|--|--|
|`vectors`|`CollisionVector<vec3>[]`|

## CollisionOBBoxVolume
|Name|Type|
|--|--|
|`halfExtents`|`vec3`|

### Children
|Name|Chunk|
|--|--|
|`vectors`|`CollisionVector<vec3>[]`|

## CollisionBBoxVolume
|Name|Type|
|--|--|
|`nothing`|`u32`|

## CollisionVector
|Name|Type|
|--|--|
|`value`|`vec3`|

## CollisionVolumeOwner
|Name|Type|
|--|--|
|`numNames`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`names`|`CollisionVolumeOwnerName[]`|

## CollisionVolumeOwnerName
|Name|Type|
|--|--|
|`name`|`string`|

## CollisionObjectAttribute
|Name|Type|
|--|--|
|`static`|`u16`|
|`defaultArea`|`u32`|
|`canRoll`|`u16`|
|`canSlide`|`u16`|
|`canSpin`|`u16`|
|`canBounce`|`u16`|
|`unknown1`|`u32`|
|`unknown2`|`u32`|
|`unknown3`|`u32`|

## FenceWrapper
|Name|Type|
|--|--|

### Children
|Name|Chunk|
|--|--|
|`fence`|`Fence`|

## Fence
|Name|Type|
|--|--|
|`start`|`vec3`|
|`end`|`vec3`|
|`normal`|`vec3`|

## Set
|Name|Type|
|--|--|
|`name`|`string`|
|`numTextures`|`u32`|

### Children
|Name|Chunk|
|--|--|
|`textures`|`Texture[]`|

