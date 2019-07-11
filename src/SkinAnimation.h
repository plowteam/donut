#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <string>
#include <vector>

namespace Donut
{

class SkinAnimation
{
public:

	class TranslationKey
	{
	public:
		TranslationKey(float time, const glm::vec3& value) :
			_time(time), _value(value) {}

		const float& GetTime() const { return _time; }
		const glm::vec3& GetValue() const { return _value; }
	private:
		float _time;
		glm::vec3 _value;
	};

	class RotationKey
	{
	public:
		RotationKey(float time, const glm::quat& value) :
			_time(time), _value(value) {}

		const float& GetTime() const { return _time; }
		const glm::quat& GetValue() const { return _value; }
	private:
		float _time;
		glm::quat _value;
	};

	class Track
	{
	public:
		Track(std::string name) :
			_name(name) {}

		glm::mat4 Evaluate(float time);
		void AddTranslationKey(float time, const glm::vec3& value) { _translationKeys.push_back(TranslationKey(time, value)); }
		void AddRotationKey(float time, const glm::quat& value) { _rotationKeys.push_back(RotationKey(time, value)); }

		glm::mat4 restPose;
	private:
		std::string _name;
		std::vector<TranslationKey> _translationKeys;
		std::vector<RotationKey> _rotationKeys;
	};

	SkinAnimation(std::string name, float length, int32_t frameCount, float frameRate) :
		_name(name), _length(length), _frameCount(frameCount), _frameRate(frameRate) {}

	glm::mat4 Evaluate(size_t trackIndex, float time);
	void AddTrack(std::unique_ptr<Track>& track) { _tracks.push_back(std::move(track)); }
	size_t GetNumTracks() const { return _tracks.size(); }

private:

	std::string _name;
	float _length;
	int32_t _frameCount;
	float _frameRate;
	std::vector<std::unique_ptr<Track>> _tracks;
};

} // namespace Donut
