// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include <string>
#include <vector>

namespace ImGui
{

bool Combo(const char* label, int* currIndex, std::vector<std::string>& values);
bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values);

} // namespace ImGui
