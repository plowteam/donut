// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <Core/BoundingBox.h>
#include "Core/BoundingSphere.h"

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

struct SkeletonJoint
{
	std::string name;
	uint32_t parent;
	glm::mat4 restPose;

	SkeletonJoint(std::string name, const uint32_t parent, const glm::mat4 restPose):
	    name(std::move(name)), parent(parent), restPose(restPose)
	{
	}
};

class Character
{
  public:
	Character(std::string name);
	void LoadModel(const std::string& name);
	void LoadAnimations(const std::string& name);

	const std::string& GetName() const { return _name; }
	const std::string& GetModelName() const { return _modelName; }
	const std::string& GetAnimName() const { return _animName; }
	void SetPosition(const glm::vec3& position);
	void SetRotation(const glm::quat& rotation);
	const glm::vec3& GetPosition() const { return _position; }
	const glm::quat& GetRotation() const { return _rotation; }
	void SetAnimation(const std::string&);
	CharacterController& GetCharacterController() const { return *_characterController; }

	void Update(double deltatime);
	void Draw(const glm::mat4& viewProjection, GL::ShaderProgram&, const ResourceManager&);

	// maybe change this to just anim names
	const std::unordered_map<std::string, std::unique_ptr<SkinAnimation>>& GetAnimations() const { return _animations; }

  private:
	void loadSkeleton(const P3D::Skeleton&);
	void addAnimation(const P3D::Animation&);

	void updateAnimation(SkinAnimation&, double time);
	double _animTime;

	// only used as an entity name for now
	std::string _name;

	std::string _modelName; // just for debug select
	std::string _animName; // just for debug select

	glm::vec3 _position;
	glm::quat _rotation;

	std::unique_ptr<CharacterController> _characterController;

	std::unique_ptr<SkinModel> _skinModel;
	// std::weak_ptr<SkinModel> _skinModel; // use when SkinModels are created as a shared_ptr
	std::vector<SkeletonJoint> _skeletonJoints;

	// animations / bone buffers
	std::unordered_map<std::string, std::unique_ptr<SkinAnimation>> _animations;
	SkinAnimation* _currentAnimation;
	std::unique_ptr<GL::TextureBuffer> _boneBuffer;
	std::vector<glm::mat4> _boneMatrices;
	std::vector<glm::mat4> _poseMatrices;
	std::vector<glm::mat4> _finalMatrices;
};
} // namespace Donut
