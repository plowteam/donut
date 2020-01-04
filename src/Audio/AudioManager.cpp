// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "AudioManager.h"

#include "Core/FileSystem.h"
#include "Render/imgui/imgui.h"

#include <array>
#include <stdexcept>

namespace Donut
{

AudioManager::AudioManager()
{
	initializeOpenAL();

	std::array<std::string, 10> files = {"dialog.rcf",   "music00.rcf",  "music01.rcf", "music02.rcf", "music03.rcf",
	                                     "carsound.rcf", "ambience.rcf", "nis.rcf",     "soundfx.rcf", "scripts.rcf"};

	for (const std::string& filename : files) LoadRCF(filename);
}

AudioManager::~AudioManager()
{
	shutdownOpenAL();

	_sounds.clear();
}

void AudioManager::LoadRCF(const std::string& filename)
{
	if (!FileSystem::exists(filename))
	{
		// log("failed to find thing")
		return;
	}

	// todo: store a map to the RCFFile
	_rcfFiles.push_back(std::make_unique<RCL::RCFFile>(filename));
}

void AudioManager::PlayAudio(const std::string& name)
{
	// find which rcf file our sound is in. todo: this will be better done in a hashmap
	std::unique_ptr<MemoryStream> rsdStream = nullptr;
	for (const auto& rcf : _rcfFiles)
	{
		rsdStream = rcf->GetFileStream(name);

		if (rsdStream != nullptr)
			break;
	}

	if (rsdStream == nullptr)
		return;

	RCL::RSDFile rsdFile(*rsdStream);
	if (_buffer != 0)
	{
		alDeleteBuffers(1, &_buffer);
	}

	alGenBuffers(1, &_buffer);

	const ALenum format = getFormat(rsdFile);
	const auto& data = rsdFile.GetData();

	alBufferData(_buffer, format, data.data(), (ALsizei)data.size(), rsdFile.GetSampleRate());
	alSourcei(_source, AL_BUFFER, _buffer);
	alSourcei(_source, AL_LOOPING, AL_FALSE);
	alSourcePlay(_source);
}

void AudioManager::DebugGUI(bool* open)
{
	ImGui::SetNextWindowSize(ImVec2(330, 400), ImGuiCond_Once);
	ImGui::Begin("RADCORE CEMENT LIBRARY", open);

	for (const auto& rcf : _rcfFiles)
	{
		if (ImGui::TreeNode(rcf->GetFileName().c_str()))
		{
			for (const auto& filename : rcf->GetFilenames())
			{
				if (ImGui::Selectable(filename.c_str()))
				{
					PlayAudio(filename);
				}
			}

			ImGui::TreePop();
		}
	}

	ImGui::End();
}

void AudioManager::initializeOpenAL()
{
	_alDevice = alcOpenDevice(nullptr);
	if (!_alDevice)
		throw std::runtime_error("Failed to open OpenAL device.");

	_alContext = alcCreateContext(_alDevice, nullptr);
	if (!_alContext)
		throw std::runtime_error("Failed to create OpenAL context.");

	alcMakeContextCurrent(_alContext);

	alGenBuffers(1, &_buffer);
	alGenSources(1, &_source);
}

void AudioManager::shutdownOpenAL()
{
	// _buffers.clear();

	if (_alContext)
	{
		alcMakeContextCurrent(nullptr);
		alcDestroyContext(_alContext);
	}
	_alContext = nullptr;

	if (_alDevice)
	{
		alcCloseDevice(_alDevice);
	}
	_alDevice = nullptr;
}

ALenum AudioManager::getFormat(const RCL::RSDFile& file) const
{
	if (file.GetNumChannels() == 1)
	{
		if (file.GetBitsPerChannel() == 8)
			return AL_FORMAT_MONO8;
		else if (file.GetBitsPerChannel() == 16)
			return AL_FORMAT_MONO16;
	}
	else if (file.GetNumChannels() == 2)
	{
		if (file.GetBitsPerChannel() == 8)
			return AL_FORMAT_STEREO8;
		else if (file.GetBitsPerChannel() == 16)
			return AL_FORMAT_STEREO16;
	}

	return AL_FORMAT_STEREO16;
}

} // namespace Donut
