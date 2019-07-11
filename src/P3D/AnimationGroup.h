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
	AnimationGroup() {}

	static std::unique_ptr<AnimationGroup> Load(const P3DChunk&);
	void LoadChannels(const P3DChunk&);

	std::unique_ptr<Vector2Channel>& GetVector2Channel() { return _vector2Channel; }
	std::unique_ptr<Vector3Channel>& GetVector3Channel() { return _vector3Channel; }
	std::unique_ptr<QuaternionChannel>& GetQuaternionChannel() { return _quaternionChannel; }
	std::unique_ptr<CompressedQuaternionChannel>& GetCompressedQuaternionChannel() { return _compressedQuaternionChannel; }

  private:
	std::unique_ptr<Vector2Channel> _vector2Channel;
	std::unique_ptr<Vector3Channel> _vector3Channel;
	std::unique_ptr<QuaternionChannel> _quaternionChannel;
	std::unique_ptr<CompressedQuaternionChannel> _compressedQuaternionChannel;
};

} // namespace Donut::P3D
