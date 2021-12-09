// Copyright 2019-2021 the donut authors. See AUTHORS.md

#pragma once

#include <string>

typedef std::size_t EntityID_t;

namespace donut::pure3d
{
class Entity
{
public:
	void SetName(const std::string& name) { _name = name; }
	std::string GetName() const { return _name; }

	virtual std::string GetClassName() const { return "Entity"; }
private:
	std::string _name;
};

} // namespace donut::pure3d
