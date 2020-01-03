// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Quaternion.h"
#include "Core/Math/Vector3.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace Donut
{
namespace GL
{
class ShaderProgram;
class TextureBuffer;
class GLTexture2D;
} // namespace GL

namespace P3D
{
class Animation;
class PolySkin;
class Shader;
class Skeleton;
class Texture;
} // namespace P3D

class CharacterController;
class SkinModel;
class SkinAnimation;
class ResourceManager;
class Skeleton;

struct SkeletonJoint
{
	std::string name;
	uint32_t parent;
	Matrix4x4 restPose;

	SkeletonJoint(std::string name, const uint32_t parent, const Matrix4x4 restPose)
	    : name(std::move(name)), parent(parent), restPose(restPose)
	{
	}
};

class Character
{
public:
	Character(std::string name);
	~Character();

	void LoadModel(const std::string& name);
	void LoadAnimations(const std::string& name);

	const std::string& GetName() const { return _name; }
	const std::string& GetModelName() const { return _modelName; }
	const std::string& GetAnimName() const { return _animName; }
	void SetPosition(const Vector3& position);
	void SetRotation(const Quaternion& rotation);
	const Vector3& GetPosition() const { return _position; }
	const Quaternion& GetRotation() const { return _rotation; }
	void SetAnimation(const std::string&);
	CharacterController& GetCharacterController() const { return *_characterController; }
	Skeleton& GetSkeleton() const { return *_skeleton; }

	void Update(double deltatime);
	void Draw(const Matrix4x4& viewProjection, GL::ShaderProgram&, const ResourceManager&);

	// maybe change this to just anim names
	const std::unordered_map<std::string, std::unique_ptr<SkinAnimation>>& GetAnimations() const { return _animations; }

private:
	void addAnimation(const P3D::Animation&);

	double _animTime;

	// only used as an entity name for now
	std::string _name;

	std::string _modelName; // just for debug select
	std::string _animName;  // just for debug select

	Vector3 _position;
	Quaternion _rotation;

	std::unique_ptr<CharacterController> _characterController;

	std::unique_ptr<SkinModel> _skinModel; // use std::weak_ptr when SkinModels are created as a shared_ptr
	std::unique_ptr<Skeleton> _skeleton;

	std::unique_ptr<GL::TextureBuffer> _boneBuffer;

	// animations / bone buffers
	std::unordered_map<std::string, std::unique_ptr<SkinAnimation>> _animations;
	SkinAnimation* _currentAnimation;
};
} // namespace Donut
