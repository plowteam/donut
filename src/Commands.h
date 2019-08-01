#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <Core/File.h>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <fmt/format.h>
#include <glm/vec3.hpp>

namespace Donut
{
    struct Command
    {
        bool(*sig)(const std::string&);
        std::string help;
    };

    class Commands
    {
    public:

		Commands() = delete;
		~Commands() = delete;

		static bool Run(const std::string& name, const std::string& params)
		{
			auto command = _namedCommands.find(name);
			if (command == _namedCommands.end())
			{
				std::cout << "command " << name << "not found" << std::endl;
				return false;
			}

			if (!command->second.sig(params))
			{
				std::cout << "error running command " << name << "(" << params << ")" << std::endl;
				return false;
			}

			return true;
		}

		static inline void ltrim(std::string &s) {
			s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
				return !std::isspace(ch);
			}));
		}

		static inline void rtrim(std::string &s) {
			s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
				return !std::isspace(ch);
			}).base(), s.end());
		}

		static bool RunScript(const std::string& filename)
		{
			if (!std::filesystem::exists(filename))
			{
				std::cout << "Script not found: " << filename << "\n";
				return false;
			}

			File file;
			file.Open(filename, FileMode::Read);

			std::unordered_map<std::string, std::string> functions;
			std::vector<std::string> lines;
			int32_t commandsRun = 0;

			while (file.Position() < file.Size())
			{
				auto line = file.ReadLine();
				if (line.empty() || std::all_of(line.begin(), line.end(), isspace)) continue;

				ltrim(line);
				rtrim(line);
				if (line[0] == '/') continue;

				std::size_t end = line.find_last_of(");");
				if (end == -1) continue;
				std::size_t start = line.find_first_of("(");
				if (start == -1) continue;

				auto name = line.substr(0, start);
				ltrim(name);
				rtrim(name);

				auto params = line.substr(start + 1, (end - start) - 2);
				ltrim(params);
				rtrim(params);

				if (Run(name, params))
				{
					commandsRun++;
				}

				lines.push_back(line);
			}

			if (commandsRun != lines.size())
			{
				std::cout << fmt::format("{0} has {1} failed commands", filename, lines.size() - commandsRun) << std::endl;
			}
			else
			{
				//std::cout << fmt::format("Successfully run {0} commands out of {1}", commandsRun, lines.size()) << std::endl;
			}

			file.Close();

			return true;
		}

    private:

        static std::unordered_map<std::string, Command> _namedCommands;

    };

	class ScriptParser
	{
	public:

		ScriptParser() = delete;
		~ScriptParser() = delete;

		static bool TryReadString(const char* data, size_t length, std::string& value, size_t& pos)
		{
			bool open = false;

			for (size_t i = 0; i < length; ++i, ++pos)
			{
				char c = data[i];
				if ((c == ' ' || c == '\t') && !open) continue;
				if (c == '"')
				{
					if (open) return true;
					else { open = true; continue; }
				}

				value.push_back(c);
			}

			return !open;
		}

		static bool TryReadInt(const char* data, size_t length, int32_t& value, size_t& pos)
		{
			bool begin = false;
			std::string valueString = "";

			for (size_t i = 0; i < length; ++i, ++pos)
			{
				char c = data[i];
				if (c == ' ' || c == '\t')
				{
					if (begin) break;
					else continue;
				}

				if (!isdigit(c))
				{
					if (begin) break;
					else if (c != '-') return false;
				}

				begin = true;
				valueString.push_back(c);
			}

			if (valueString.empty()) return false;

			value = atoi(valueString.c_str());

			return true;
		}

		static bool TryReadFloat(const char* data, size_t length, float& value, size_t& pos)
		{
			bool begin = false;
			bool hasDecimal = false;
			std::string valueString = "";

			for (size_t i = 0; i < length; ++i, ++pos)
			{
				char c = data[i];
				if (c == ' ' || c == '\t')
				{
					if (begin) break;
					else continue;
				}

				if (!begin && c == ',') continue;

				if (!isdigit(c))
				{
					if (begin)
					{
						if (c != '.') break;
						else
						{
							if (hasDecimal) return false;
							hasDecimal = true;
						}
					}
					else if (c == '.') hasDecimal = true;
					else if (c != '-') return false;
				}

				begin = true;
				valueString.push_back(c);
			}

			if (valueString.empty()) return false;

			value = (float)atof(valueString.c_str());

			return true;
		}

		static bool TryReadVec3(const char* data, size_t length, glm::vec3& value, size_t& pos)
		{
			bool isText = false;
			std::string text;
			size_t startPos = pos;

			for (size_t i = 0; i < length; ++i, ++pos)
			{
				char c = data[i];
				if (c == ' ' || c == '\t')
				{
					if (isText) return false;
					else continue;
				}

				if (isText)
				{
					if (c == ',') break;
					text.push_back(c);
					continue;
				}

				if (isdigit(c) || c == '.' || c == '-')
				{
					float x, y, z;
					if (!TryReadFloat(&data[pos - startPos], length, x, pos)) return false;
					if (!TryReadFloat(&data[pos - startPos], length, y, pos)) return false;
					if (!TryReadFloat(&data[pos - startPos], length, z, pos)) return false;
					value = glm::vec3(x, y, z);
					return true;
				}
				else
				{
					isText = true;
					text.push_back(c);
				}
			}

			if (isText)
			{
				text = text;
			}

			return true;
		}

		static bool SkipWhitespace(const char* data, size_t& pos, size_t length, size_t paramIndex)
		{
			while (pos < length - 1)
			{
				auto c = data[pos];
				if (c == ' ' || c == '\t')
				{
					pos++; continue;
				}
				else if (c == ',' && pos < length - 1)
				{
					pos++; return true;
				}
				else return true;
			}

			return true;
		}
	};
}
