#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/BillboardQuad.h>
#include <memory>
#include <string>
#include <vector>

namespace Donut::P3D
{
class BillboardQuadGroup
{
public:
	BillboardQuadGroup(const std::string& name, const std::string& shader, std::vector<std::unique_ptr<BillboardQuad>> quads):
		_shader(shader), _quadGroups(std::move(quads))
	{
	}

	static std::unique_ptr<BillboardQuadGroup> Load(const P3DChunk&);

	const std::string& GetName() const { return _name; }
	const std::vector<std::unique_ptr<BillboardQuad>>& GetQuads() const { return _quadGroups; }

private:
	std::string _name;
	std::string _shader;
	std::vector<std::unique_ptr<BillboardQuad>> _quadGroups;
};
} // namespace Donut::P3D
