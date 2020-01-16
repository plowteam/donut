// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <string>
#include <memory>
#include <vector>

namespace Donut
{

class Quaternion;
class Sound;
class Vector3;

typedef unsigned int SoundBuffer;

/**
 * A generic interface to an audio implementation.
 */
class IAudioManager
{
public:
	virtual void Play(const std::string& name, bool looping) = 0;
	virtual void Play3D(const std::string& name, const Vector3& position, bool looping) = 0;

	virtual void UpdateListenerTransform(const Vector3& position, const Quaternion& orientation, const Vector3& velocity) = 0;

	virtual void DebugGUI(bool* open) = 0;

	/*virtual std::pair<SoundBuffer, std::size_t> LoadSound(const std::vector<std::byte>& data, uint32_t numChannels, uint32_t bitsPerChannel,
	                                                      uint32_t sampleRate) = 0;
	virtual std::size_t UnloadSound(SoundBuffer buffer) = 0;

	virtual bool PlaySound(Sound* sound, SoundBuffer buffer) = 0;
	virtual bool IsSoundPlaying(Sound* sound) = 0;
	virtual void UpdateSound(Sound* sound) = 0;
	virtual void FinishSound(Sound* sound) = 0;

	virtual void UpdateListenerTransform(const Vector3& position, const Quaternion& orientation, const Vector3& velocity) = 0;*/
};

} // namespace Donut
