// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "ALAudioManager.h"

#include "Core/FileSystem.h"
#include "Core/Log.h"
#include "Render/imgui/imgui.h"

#include <SDL.h>

#include <array>
#include <stdexcept>
#include <thread>

namespace Donut
{

/**
 * AudioManagerWorker manages active sounds etc..
 */
class ALAudioManagerWorker
{
public:
	ALAudioManagerWorker() { _workerThread = std::thread(RunThread, this); }

private:
	static void RunThread(ALAudioManagerWorker* worker) { worker->Run(); }

	void Run()
	{
		while (true) { SDL_Delay(500); }
	}

	std::thread _workerThread;
};

ALAudioManager::ALAudioManager()
{
	initializeAL();
}

ALAudioManager::~ALAudioManager()
{
	_sounds.clear();
}

bool ALAudioManager::initializeAL()
{
	Log::Debug("Initializing OpenAL driver\n\n");

	// open default audio device
	_alDevice = alcOpenDevice(nullptr);
	if (_alDevice == nullptr)
	{
		alError("Failed to open AL device");
		return false;
	}

	const ALCchar* deviceName = alcGetString(_alDevice, ALC_DEVICE_SPECIFIER);
	Log::Debug("[OpenAL] AudioDevice opened: {}\n", deviceName);

	_alContext = alcCreateContext(_alDevice, nullptr);
	if (_alContext == nullptr)
		return false;

	alcMakeContextCurrent(_alContext);

	if (alError("InitializeAL"))
	{
		Log::Debug("ALAudio: alcMakeContextCurrent failed.");
		return false;
	}

	Log::Debug("Initialized OpenAL driver:\n\tAL Version: {}\n\tAL Renderer: {}\n\tAL Vendor: {}\n", alGetString(AL_VERSION),
	           alGetString(AL_RENDERER), alGetString(AL_VENDOR));

	alError("Emptying error stack", false);

	// allocate our audio sources
	for (int i = 0; i < NumALAudioSources; i++)
	{
		ALuint sourceID;
		alGenSources(1, &sourceID);

		if (alError("Init (creating sources)"))
			break;

		_alSources.push_back(sourceID);
		_alFreeSources.push_back(sourceID);
	}

	Log::Debug("AudioDevice: allocated {} sources.\n", _alSources.size());

	alDistanceModel(AL_EXPONENT_DISTANCE);
}

void ALAudioManager::LoadResources(const std::vector<std::string>& soundFiles)
{
	for (auto const& file : soundFiles)
	{
		if (!FileSystem::exists(file))
		{
			Log::Error("Failed to find {}\n", file);
			continue;
		}

		_rcfFiles.push_back(std::make_unique<RCL::RCFFile>(file));
	}
}

void ALAudioManager::PlaySound(const std::string& name, float volume, float pitch, AudioType type)
{
	const uint32_t hash = RCL::StringHash(name);
	Log::Debug("PlayAudio: {} w/ hash {:x}\n", name, hash);

	auto const buffer = _bufferHashMap.find(hash);
	if (buffer != _bufferHashMap.end())
	{
		Log::Debug("Play already loaded sound: {} {} bytes\n", buffer->second.first, buffer->second.second);
		//_audioDevice->PlaySound(nullptr, buffer->second.first);
		return;
	}

	//	auto rsdFile = *getRSDFile(name);
	//	const auto& data = rsdFile.GetData();

	/*auto soundPair =
	    _audioDevice->LoadSound(data, rsdFile.GetNumChannels(), rsdFile.GetBitsPerChannel(), rsdFile.GetSampleRate());
	Log::Debug("Loaded Sound: {} {} bytes\n", soundPair.first, soundPair.second);

	_bufferHashMap[hash] = soundPair;

	_audioDevice->PlaySound(nullptr, soundPair.first);*/
}

std::pair<ALuint, std::size_t> ALAudioManager::loadSound(uint32_t hash)
{
	std::unique_ptr<MemoryStream> rsdStream = nullptr;
	for (const auto& rcf : _rcfFiles)
	{
		rsdStream = rcf->GetFileStream(hash);

		if (rsdStream != nullptr)
			break;
	}

	if (rsdStream == nullptr)
		return std::make_pair(0, 0);

	/*const auto& data = rsdFile.GetData();
	ALenum format = getALFormat(channels, bpc);

	ALint size;
	ALuint buffer = AL_NONE;
	alGenBuffers(1, &buffer);
	// todo: additional error checking
	alBufferData(buffer, format, data.data(), data.size(), sampleRate);
	alGetBufferi(buffer, AL_SIZE, &size);
	if (alError("LoadSound"))
	{
		if (alIsBuffer(buffer))
			alDeleteBuffers(1, &buffer);
		return std::make_pair(AL_NONE, 0);
	}

	return std::make_pair(buffer, size);*/
	return std::make_pair(0, 0);
}

void ALAudioManager::DebugGUI(bool* open)
{
	ImGui::SetNextWindowSize(ImVec2(330, 400), ImGuiCond_Once);
	ImGui::Begin("Audio Manager", open);

	auto devices = GetOutputDevices();
	int index = 0;
	float volume = 1.0f;

	ImGui::Text("Audio Device:");
	ImGui::PushItemWidth(-1);
	ImGui::Combo("##device", &index, devices);

	ImGui::Text("Master Volume:");
	ImGui::SliderFloat("##volume", &volume, 0.0f, 1.0f, "volume = %.2f");

	ImGui::Separator();

	ImGui::Text("Free Sources: %d/%d", _alFreeSources.size(), _alSources.size());

	ImGui::Separator();

	ImGui::BeginChild("##selector");

	for (const auto& rcf : _rcfFiles)
	{
		if (ImGui::TreeNode(rcf->GetFileName().c_str()))
		{
			for (const auto& filename : rcf->GetFilenames())
			{
				if (ImGui::Selectable(filename.c_str()))
				{
					PlaySound(filename, 1.0f, 1.0f, AudioType::Effect);
				}
			}

			ImGui::TreePop();
		}
	}

	ImGui::EndChild();

	ImGui::End();
}

ALenum ALAudioManager::getALFormat(int numChannels, int bitsPerChannel)
{
	struct ALFormat
	{
		ALenum format;
		int channels;
		int bpc;
	};

	static const std::array<ALFormat, 4> fmtList {{
	    {AL_FORMAT_MONO8, 1, 8},
	    {AL_FORMAT_MONO16, 1, 16},
	    {AL_FORMAT_STEREO8, 2, 8},
	    {AL_FORMAT_STEREO16, 2, 16},
	}};

	for (auto const& fmt : fmtList)
	{
		if (fmt.channels == numChannels && fmt.bpc == bitsPerChannel)
			return fmt.format;
	}

	Log::Warn("Unsupported sound format: {} channels, {} bits per channel.", numChannels, bitsPerChannel);
	return AL_NONE;
}

std::vector<std::string> ALAudioManager::GetOutputDevices()
{
	std::vector<std::string> devices;

	if (alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT") == AL_FALSE)
		return devices;

	bool enumerateAll = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT") == AL_TRUE;

	const ALCchar* s = alcGetString(NULL, enumerateAll ? ALC_ALL_DEVICES_SPECIFIER : ALC_DEVICE_SPECIFIER);
	while (*s != '\0')
	{
		// todo: can we get rid of "OpenAL Soft" from each device?
		devices.push_back(std::string(s));
		while (*s++ != '\0')
			;
	}

	return devices;
}

bool ALAudioManager::alError(const std::string& text, bool print)
{
	ALenum error = alGetError();

	if (error == AL_NO_ERROR)
		return false;

	do
	{
		if (!print)
			continue;

		switch (error)
		{
		case AL_INVALID_NAME: Log::Debug("ALAudio: AL_INVALID_NAME in %s\n", text); break;
		case AL_INVALID_VALUE: Log::Debug("ALAudio: AL_INVALID_VALUE in %s\n", text); break;
		case AL_OUT_OF_MEMORY: Log::Debug("ALAudio: AL_OUT_OF_MEMORY in %s\n", text); break;
		case AL_INVALID_ENUM: Log::Debug("ALAudio: AL_INVALID_ENUM in %s\n", text); break;
		case AL_INVALID_OPERATION: Log::Debug("ALAudio: AL_INVALID_OPERATION in %s\n", text); break;
		default: Log::Debug("ALAudio: Unknown Error NUM in %s\n", text); break;
		}
	} while ((error = alGetError()) != AL_NO_ERROR);

	return true;
}

} // namespace Donut
