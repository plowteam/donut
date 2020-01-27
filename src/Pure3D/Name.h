// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstdint>
#include <string>

namespace Donut
{

class Name
{
public:
	Name();
	Name(std::string text);

	void SetName(const std::string& text);
	std::string GetName() const;

private:
	std::string _name;
};

} // namespace Donut
