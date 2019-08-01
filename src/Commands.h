#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <charconv>
#include <Core/File.h>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <fmt/format.h>
#include <glm/vec3.hpp>
#include <GameCommands.h>

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

        static bool StringToInt64(const std::string& s, int64_t& v)
        {
            return std::from_chars(s.data(), s.data() + s.size(), v).ec == std::errc();
        }

        static bool StringToInt(const std::string& s, int32_t& v)
        {
            return std::from_chars(s.data(), s.data() + s.size(), v).ec == std::errc();
        }

        static bool StringToFloat(const std::string& s, float& v)
        {
            char* end;
            v = std::strtof(s.c_str(), &end);
            return end != nullptr;
        }

        static bool SplitParams(const std::string& s, std::vector<std::string>& params, size_t maxParams)
        {
            auto length = s.size();
            if (length == 0) return true;

            bool openQuote = false;
            std::string param = "";

            for (size_t i = 0; i < length; ++i)
            {
                auto c = s[i];
                if (c == '"')
                {
                    openQuote = !openQuote;
                    continue;
                }
                else if (c == ',' && !openQuote)
                {
					if (param.empty()) return false;
					if (params.size() >= maxParams) return false;

                    trim(param);
                    params.push_back(param);
                    param.clear();

                    continue;
                }

                param.push_back(c);
            }

			if (openQuote || param.empty()) return false;
			if (params.size() >= maxParams) return false;

            trim(param);
            params.push_back(param);

            return true;
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

                trim(line);
                if (line[0] == '/') continue;

				std::size_t commentPos = line.find_first_of("//");
				if (commentPos != -1)
				{
					line = line.substr(0, commentPos);
					trim(line);
				}

				std::size_t end = line.find_last_of(");");
                if (end == -1) continue;
                std::size_t start = line.find_first_of("(");
                if (start == -1) continue;

                auto name = line.substr(0, start);
                trim(name);

                auto params = line.substr(start + 1, (end - start) - 2);
                trim(params);

                if (Run(name, params))
                {
                    commandsRun++;
                }

                lines.push_back(line);
            }

			file.Close();

            if (commandsRun != lines.size())
            {
                std::cout << fmt::format("{0} has {1} failed commands", filename, lines.size() - commandsRun) << std::endl;
				return false;
            }
            else
            {
                //std::cout << fmt::format("Successfully run {0} commands out of {1}", commandsRun, lines.size()) << std::endl;
            }

            return true;
        }

    private:

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

        static inline void trim(std::string &s) {
            ltrim(s);
            rtrim(s);
        }

        static std::unordered_map<std::string, Command> _namedCommands;

    };
}
