// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

/*namespace Donut
{

class Quaternion;
class Vector3;

class ALAudioDevice : public IAudioDevice
{
public:
	ALAudioDevice(const std::string& deviceName = "");
	~ALAudioDevice();

	void UpdateListenerTransform(const Vector3& position, const Quaternion& orientation, const Vector3& velocity) override;

	bool PlaySound(Sound* sound, SoundBuffer buffer) override;

	std::pair<SoundBuffer, std::size_t> LoadSound(const std::vector<std::byte>& data, uint32_t numChannels,
	                                              uint32_t bitsPerChannel, uint32_t sampleRate) override;
	std::size_t UnloadSound(SoundBuffer buffer) override;

	void ReleaseALSource(ALuint source);

	static std::vector<std::string> GetOutputDevices();
protected:
	friend class AudioManager;

	bool initializeAL();
	bool alError(const std::string& text, bool print = true);

	static const int NumAudioSources = 64;

	ALCdevice* _device;
	ALCcontext* _context;

	std::vector<ALuint> _sources;
	std::deque<ALuint> _freeSources;

	std::vector<ALuint> _usedBuffers;
	// std::deque<ALuint> _freeBuffers;

	static ALenum getALFormat(int numChannels, int bitsPerChannel);
};*/

} // namespace Donut
