#pragma once

#include <P3D/P3DChunk.h>

namespace Donut::P3D
{
	class CompositeDrawable
	{
	public:

		CompositeDrawable()
		{
		}

		static std::unique_ptr<CompositeDrawable> Load(const P3DChunk&);

	private:

	};
} // namespace Donut::P3D
