// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <string>

namespace Donut
{

class Object
{
public:
	void SetName(const std::string& name);
	std::string GetName() const;

	virtual std::string GetClassName() const { return "Object"; }
private:
	std::string _name;
};

} // namespace Donut
