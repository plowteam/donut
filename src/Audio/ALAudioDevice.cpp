// Copyright 2019-2020 the donut authors. See AUTHORS.md

/*#include "ALAudioDevice.h"

#include "Core/Log.h"
#include "Core/Math/Quaternion.h"
#include "Core/Math/Vector3.h"

#include <array>
#include <stdexcept>

namespace Donut
{

ALAudioDevice::ALAudioDevice(const std::string& deviceName): _device(nullptr), _context(nullptr)
{
	initializeAL();
}

ALAudioDevice::~ALAudioDevice()
{
	alDeleteSources(_sources.size(), _sources.data());

	alcMakeContextCurrent(nullptr);
	alcDestroyContext(_context);
	_context = nullptr;

	if (_device)
	{
		const ALCchar* deviceName = alcGetString(_device, ALC_ALL_DEVICES_SPECIFIER);
		Log::Debug("AudioDevice closing: {}\n", deviceName);

		alcCloseDevice(_device);
		_device = nullptr;
	}
}

bool ALAudioDevice::initializeAL()
{
	Log::Debug("Initializing OpenAL driver\n\n");

	// open default audio device
	_device = alcOpenDevice(nullptr);
	if (_device == nullptr)
	{
		alError("Failed to open device");
		return false;
	}

	const ALCchar* deviceName = alcGetString(_device, ALC_DEVICE_SPECIFIER);
	Log::Debug("[OpenAL] AudioDevice opened: {}\n", deviceName);

	_context = alcCreateContext(_device, nullptr);
	if (_context == nullptr)
		return false;

	alcMakeContextCurrent(_context);

	if (alError("InitializeAL"))
	{
		Log::Debug("ALAudio: alcMakeContextCurrent failed.");
		return false;
	}

	Log::Debug("Initialized OpenAL driver:\n\tAL Version: {}\n\tAL Renderer: {}\n\tAL Vendor: {}\n", alGetString(AL_VERSION),
	           alGetString(AL_RENDERER), alGetString(AL_VENDOR));

	alError("Emptying error stack", false);

	// allocate our audio sources
	for (int i = 0; i < NumAudioSources; i++)
	{
		ALuint sourceID;
		alGenSources(1, &sourceID);

		if (alError("Init (creating sources)"))
			break;

		_sources.push_back(sourceID);
		_freeSources.push_back(sourceID);
	}

	Log::Debug("AudioDevice: allocated {} sources.\n", _sources.size());

	alDistanceModel(AL_EXPONENT_DISTANCE);
}

bool ALAudioDevice::alError(const std::string& text, bool print)
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

std::pair<ALuint, std::size_t> ALAudioDevice::LoadSound(const std::vector<std::byte>& data, uint32_t channels, uint32_t bpc,
                                                        uint32_t sampleRate)
{
	ALenum format = getALFormat(channels, bpc);

	ALint size;
	ALuint buffer = AL_NONE;
	alGenBuffers(1, &buffer);
	// todo: additional error checking
	alBufferData(buffer, format, data.data(), data.size(), sampleRate);
	alGetBufferi(buffer, AL_SIZE, &size);
	if (alError("LoadSound")) {
		if (alIsBuffer(buffer))
			alDeleteBuffers(1, &buffer);
		return std::make_pair(AL_NONE, 0);
	}

	// track our used buffers, we can free them afterwards
	_usedBuffers.push_back(buffer);

	return std::make_pair(buffer, size);
}

std::size_t ALAudioDevice::UnloadSound(SoundBuffer buffer)
{
	// todo: make sure no sources are playing this buffer

	ALint size = 0;
	alGetBufferi(buffer, AL_SIZE, &size);
	alDeleteBuffers(1, &buffer);

	// dunno if we need to bother tracking these
	auto lambda = [buffer](ALuint a) { return a == buffer; };
	auto rem = std::remove_if(_usedBuffers.begin(), _usedBuffers.end(), lambda);
	_usedBuffers.erase(rem, _usedBuffers.end());

	return size;
}

bool ALAudioDevice::PlaySound(Sound* sound, SoundBuffer buffer)
{
	if (_freeSources.empty())
	{
		Log::Warn("No free AL sources!\n");
		return false;
	}

	ALuint source = _freeSources.front();

	alSourcei(source, AL_BUFFER, buffer);
	alSourcei(source, AL_LOOPING, AL_FALSE);
	// if error rewind
	alSourcePlay(source);

	_freeSources.pop_front();
	// sound->sourceHandle = source;
	// _activeSounds.push_back(sound);

	return true;
}

void ALAudioDevice::UpdateListenerTransform(const Vector3& position, const Quaternion& orientation, const Vector3& velocity)
{
	// Update position
	alListenerfv(AL_POSITION, position.Data());

	// Update orientation (convert our quat into 2 vecs)
	auto up = orientation * Vector3::Up;
	auto at = orientation * Vector3::Right;
	float alOrientation[6] = {at.X, at.Y, at.Z, up.X, up.Y, up.Z};
	alListenerfv(AL_ORIENTATION, alOrientation);

	// Update velocity...
	alListenerfv(AL_VELOCITY, velocity.Data());
}

ALenum ALAudioDevice::getALFormat(int numChannels, int bitsPerChannel)
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

std::vector<std::string> ALAudioDevice::GetOutputDevices()
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

} */ // namespace Donut
