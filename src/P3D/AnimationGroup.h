#pragma once

#include <P3D/CompressedQuaternionChannel.h>
#include <P3D/P3DChunk.h>
#include <P3D/QuaternionChannel.h>
#include <P3D/Vector2Channel.h>
#include <P3D/Vector3Channel.h>
#include <memory>

namespace Donut::P3D
{

class AnimationGroup
{
  public:
	AnimationGroup(const std::string& name, uint32_t groupId) :
		_name(name), _groupId(groupId) {}

	static std::unique_ptr<AnimationGroup> Load(const P3DChunk&);
	void LoadChannels(const P3DChunk&);

	const std::string& GetName() const { return _name; }
	uint32_t GetGroupId() const { return _groupId; }

	const Vector2Channel* GetVector2Channel() const { return _vector2Channel.get(); }
	const Vector3Channel* GetVector3Channel() const { return _vector3Channel.get(); }
	const QuaternionChannel* GetQuaternionChannel() const { return _quaternionChannel.get(); }
	const CompressedQuaternionChannel* GetCompressedQuaternionChannel() const { return _compressedQuaternionChannel.get(); }

  private:
	std::string _name;
	uint32_t _groupId;
	std::unique_ptr<Vector2Channel> _vector2Channel;
	std::unique_ptr<Vector3Channel> _vector3Channel;
	std::unique_ptr<QuaternionChannel> _quaternionChannel;
	std::unique_ptr<CompressedQuaternionChannel> _compressedQuaternionChannel;
};

} // namespace Donut::P3D
