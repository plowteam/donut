// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

namespace Donut
{

class Sound
{
public:
	Sound() = default;
	~Sound() = default;

	bool IsPlaying() const;

	void Play();
	void Stop();



	void SetPosition();
};

} // namespace Donut
