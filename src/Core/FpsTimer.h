// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

namespace Donut
{
class FpsTimer
{

public:
	FpsTimer(): m_fps(0), m_oldFps(0.0), m_frameCount(0), m_frameTime(0.0) {}

	void Update(double time)
	{
		m_frameTime = time;
		++m_frameCount;
		m_oldFps += time;

		if (m_oldFps >= 1.0)
		{
			m_fps = m_frameCount;
			m_frameCount = 0;
			m_oldFps = 0.0;
		}
	}

	inline int GetFps() const { return m_fps; }
	inline double GetFrameTime() const { return m_frameTime; }

private:
	int m_fps;
	double m_oldFps;
	int m_frameCount;
	double m_frameTime;
};
} // namespace Donut
