// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Quaternion.h"
#include "Core/Math/Vector3.h"

#include <memory>
#include <string>
#include <vector>

namespace Donut
{

class SkinAnimation
{
  public:
	template <class T>
	class ValueKey
	{
	  public:
		ValueKey(float time, const T& value):
		    _time(time), _value(value) {}

		virtual T Lerp(const T& b, float time) = 0;

		float GetTime() const { return _time; }
		const T& GetValue() const { return _value; }

	  protected:
		float _time;
		T _value;
	};

	class TranslationKey: public ValueKey<Vector3>
	{
	  public:
		TranslationKey(float time, const Vector3& value):
		    ValueKey(time, value) {}

		virtual Vector3 Lerp(const Vector3& b, float time) override
		{
			return b; // TODO
			// return glm::mix(_value, b, time);
		}
	};

	class RotationKey: public ValueKey<Quaternion>
	{
	  public:
		RotationKey(float time, const Quaternion& value):
		    ValueKey(time, value) {}

		virtual Quaternion Lerp(const Quaternion& b, float time) override
		{
			return b; // TODO
			// return glm::slerp(_value, b, time);
		}
	};

	template <class T>
	class ValueKeyCurve
	{
	  public:
		void AddTranslationKey(float time, const Vector3& value) { _keyValues.push_back(std::make_unique<TranslationKey>(time, value)); }
		void AddRotationKey(float time, const Quaternion& value) { _keyValues.push_back(std::make_unique<RotationKey>(time, value)); }

		T Evalulate(float time, T defaultValue)
		{
			auto count = _keyValues.size();
			if (count == 0) return defaultValue;

			auto lastIndex = _keyValues.size() - 1;
			time           = glm::mod(time, _keyValues[lastIndex]->GetTime());

			auto index = GetKeyValueIndex(time);
			if (index == -1) return _keyValues[0]->GetValue();

			if (index == lastIndex)
			{
				return _keyValues[lastIndex]->GetValue();
			}

			auto nextIndex        = (index == lastIndex) ? 0 : index + 1;
			const auto& prevPoint = _keyValues[index];
			const auto& nextPoint = _keyValues[nextIndex];
			auto delta            = nextPoint->GetTime() - prevPoint->GetTime();

			if (delta > 0.0f)
			{
				auto fraction = (time - prevPoint->GetTime()) / delta;
				fraction      = Math::Clamp(fraction, 0.0f, 1.0f);

				return prevPoint->Lerp(nextPoint->GetValue(), fraction);
			}
			else
			{
				return _keyValues[index]->GetValue();
			}
		}

	  private:
		std::vector<std::unique_ptr<ValueKey<T>>> _keyValues;

		size_t GetKeyValueIndex(float time)
		{
			size_t count     = _keyValues.size();
			size_t lastIndex = count - 1;

			if (time < _keyValues.at(0)->GetTime())
			{
				return -1;
			}

			if (time >= _keyValues.at(lastIndex)->GetTime())
			{
				return lastIndex;
			}

			size_t minIndex = 0;
			size_t maxIndex = count;

			while (maxIndex - minIndex > 1)
			{
				auto midIndex = (minIndex + maxIndex) / 2;

				if (_keyValues.at(midIndex)->GetTime() <= time)
				{
					minIndex = midIndex;
				}
				else
				{
					maxIndex = midIndex;
				}
			}

			return minIndex;
		}
	};

	class Track
	{
	  public:
		Track(std::string name):
		    _name(name) {}

		Matrix4x4 Evaluate(float time);

		void AddTranslationKey(float time, const Vector3& value) { _translationKeys.AddTranslationKey(time, value); }
		void AddRotationKey(float time, const Quaternion& value) { _rotationKeys.AddRotationKey(time, value); }

	  private:
		std::string _name;
		ValueKeyCurve<Vector3> _translationKeys;
		ValueKeyCurve<Quaternion> _rotationKeys;
	};

	SkinAnimation(std::string name, float length, int32_t frameCount, float frameRate):
	    _name(name), _length(length), _frameCount(frameCount), _frameRate(frameRate) {}

	Matrix4x4 Evaluate(size_t trackIndex, float time);

	void AddTrack(std::unique_ptr<Track>& track) { _tracks.push_back(std::move(track)); }
	size_t GetNumTracks() const { return _tracks.size(); }
	const std::string& GetName() const { return _name; }
	float GetFrameRate() const { return _frameRate; }

  private:
	std::string _name;
	float _length;
	int32_t _frameCount;
	float _frameRate;
	std::vector<std::unique_ptr<Track>> _tracks;
};

} // namespace Donut
