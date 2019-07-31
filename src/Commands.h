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

		static void RunScript(const std::string& filename)
		{
			if (!std::filesystem::exists(filename))
			{
				std::cout << "Script not found: " << filename << "\n";
				return;
			}

			File file;
			file.Open(filename, FileMode::Read);

			std::unordered_map<std::string, std::string> functions;
			std::vector<std::string> lines;
			int32_t commandsRun = 0;

			while (!file.IsEOF())
			{
				auto line = file.ReadLine();
				if (line.empty() || std::all_of(line.begin(), line.end(), isspace)) continue;

				ltrim(line);
				if (line[0] == '/') continue;

				std::size_t end = line.find_last_of(");");
				if (end == -1) continue;
				std::size_t start = line.find_first_of("(");
				if (start == -1) continue;

				auto name = line.substr(0, start);
				auto params = line.substr(start + 1, (end - start) - 2);

				if (Run(name, params))
				{
					commandsRun++;
				}

				lines.push_back(line);
			}

			std::cout << fmt::format("Successfully run {0} commands out of {1}", commandsRun, lines.size());

			file.Close();
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
				if (c == ' ' && !open) continue;
				if (c == '"')
				{
					if (open) return true;
					else { open = true; continue; }
				}

				if (!open) return false;

				value.push_back(c);
			}

			return false;
		}

		static bool TryReadInt(const char* data, size_t length, int32_t& value, size_t& pos)
		{
			bool begin = false;
			std::string valueString = "";

			for (size_t i = 0; i < length; ++i, ++pos)
			{
				char c = data[i];;
				if (c == ' ')
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
				char c = data[i];;
				if (c == ' ')
				{
					if (begin) break;
					else continue;
				}

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
					else if (c != '-') return false;
				}

				begin = true;
				valueString.push_back(c);
			}

			if (valueString.empty()) return false;

			value = (float)atof(valueString.c_str());

			return true;
		}

		static bool SkipWhitespace(char c, size_t& pos, size_t length, size_t paramIndex)
		{
			if (c == ' ') pos++;
			else if (c == ',' && pos < length - 1) pos++;
			else if (paramIndex > 0) return false;
			return true;
		}
	};
}
