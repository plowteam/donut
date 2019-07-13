#pragma once

#include <P3D/P3DChunk.h>
#include <memory>
#include <string>

namespace Donut::P3D
{
class BillboardQuad
{
public:
	BillboardQuad(const std::string& name):
		_name(name)
	{
	}

	static std::unique_ptr<BillboardQuad> Load(const P3DChunk&);

	const std::string& GetName() const { return _name; }

private:
	std::string _name;
};
} // namespace Donut::P3D
