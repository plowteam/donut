// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Audio/IAudioManager.h"
#include "RCL/RCFFile.h"
#include "RCL/RSDFile.h"

#define AL_NO_PROTOTYPES 1
#define ALC_NO_PROTOTYPES 1

#include <AL/al.h>
#include <AL/alc.h>

#include <deque>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace Donut
{

static const int NumALAudioSources = 64;

enum class AudioType
{
	Music,
	Effect,
	Vehicle,
	Voice
};

/**
 * Audio in Simpsons is 3D.
 * Audio Categories:
 * - Music
 * - Effects (UI + Ingame Sounds)
 * - Vehicles
 * - Voice (Also controls ingame movies)
 */
class ALAudioManager
{
public:
	ALAudioManager();
	~ALAudioManager();

	void LoadResources(const std::vector<std::string>& soundFiles);

	// Play a sound, independently of 3d position
	// ret Sound*
	void PlaySound(const std::string& name, float volume, float pitch, AudioType type);
	void PlaySound3D(const std::string& name, const Vector3& position, float volume, float pitch, AudioType type);

	void PlaySound(uint32_t hash, float volume, float pitch, AudioType type);
	void PlaySound3D(uint32_t hash, const Vector3& position, float volume, float pitch, AudioType type);

	
	void DebugGUI(bool* open);
private:
	ALAudioManager(const ALAudioManager&) = delete;
	ALAudioManager(ALAudioManager&&) = delete;

	// load a sound into an AL buffer
	std::pair<ALuint, std::size_t> loadSound(uint32_t hash);

	float _masterVolume;
	float _musicVolume;
	float _effectsVolume;
	float _vehiclesVolume;
	float _voiceVolume;

	// OpenAL
	bool initializeAL();
	ALCdevice* _alDevice;
	ALCcontext* _alContext;
	std::vector<ALuint> _alSources;
	std::deque<ALuint> _alFreeSources;

	// std::unique_ptr<RCL::RSDFile> getRSDFile(const std::string& name);
	std::unordered_map<uint32_t, std::pair<ALuint, std::size_t>> _bufferHashMap; // todo: not reliant on OpenAL
	std::vector<std::unique_ptr<RCL::RCFFile>> _rcfFiles;
	// Containers for sounds
	std::unordered_map<std::string, RCL::RCFFile*> _sounds;

	static ALenum getALFormat(int numChannels, int bitsPerChannel);
	static bool alError(const std::string& text, bool print = true);

		/*void SetMasterVolume(float volume);
void SetMusicVolume(float volume);
void SetEffectsVolume(float volume);
void SetVehiclesVolume(float volume);
void SetVoiceVolume(float volume);

float GetMasterVolume() const;
float GetMusicVolume() const;
float GetEffectsVolume() const;
float GetVehiclesVolume() const;
float GetVoiceVolume() const;*/

public:
	static std::vector<std::string> GetOutputDevices();
};

} // namespace Donut
