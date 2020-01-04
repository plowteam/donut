// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "RCL/RCFFile.h"
#include "RCL/RSDFile.h"

#include <AL/alc.h>
#include <AL/alext.h>
#include <AL/efx.h>

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace Donut
{

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void LoadRCF(const std::string& filename);

	void PlayAudio(const std::string& name);
	void PlayAudio(uint32_t hash);

	void DebugGUI(bool* open);

private:
	void initializeOpenAL();
	void shutdownOpenAL();

	ALenum getFormat(const RCL::RSDFile& file) const;

	ALCcontext* _alContext;
	ALCdevice* _alDevice;

	std::vector<std::unique_ptr<RCL::RCFFile>> _rcfFiles;

	// Containers for sounds
	std::unordered_map<std::string, RCL::RCFFile*> _sounds;

	unsigned int _buffer, _source;
};

} // namespace Donut
