// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "Name.h"

namespace Donut
{

Name::Name() {}

Name::Name(std::string text)
{
	SetName(text);
}

void Name::SetName(const std::string& name)
{
	_name = name;
}

std::string Name::GetName() const
{
	return _name;
}

} // namespace Donut
