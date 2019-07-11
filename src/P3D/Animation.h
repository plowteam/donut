#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/AnimationGroupList.h>
#include <memory>
#include <string>

namespace Donut::P3D
{

class Animation
{
  public:
	Animation(std::string name, std::string animType, float numFrames, float frameRate, uint32_t looping, std::unique_ptr<AnimationGroupList>& groupList):
	    _name(name), _animType(animType), _numFrames(numFrames), _frameRate(frameRate), _looping(looping), _groupList(std::move(groupList)) {}

	static std::unique_ptr<Animation> Load(const P3DChunk&);

	const AnimationGroupList* GetGroupList() const { return _groupList.get(); }
	const std::string& GetName() const { return _name; }
	const std::string& GetAnimType() const { return _animType; }
	float GetNumFrames() const { return _numFrames; }
	float GetFrameRate() const { return _frameRate; }
	uint32_t GetLooping() const { return _looping; }

  private:
	std::string _name;
	std::string _animType;
	float _numFrames;
	float _frameRate;
	uint32_t _looping;
	std::unique_ptr<AnimationGroupList> _groupList;
};

} // namespace Donut::P3D
