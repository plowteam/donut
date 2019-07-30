#pragma once

#include <string>
#include <unordered_map>

namespace Donut
{
	struct Command
	{
		void(*sig)(const std::string&);
		std::string help;
	};

	class Commands
	{
	public:

		static void Run(const std::string& name, const std::string& params);

	private:

		static std::unordered_map<std::string, Command> NamedCommands;

	};
}
