// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Object.h"

namespace Donut
{

void Object::SetName(const std::string& name)
{
	_name = name;
}

std::string Object::GetName() const
{
	return _name;
}

} // namespace Donut
