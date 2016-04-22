#pragma once
#include <string>
#include <vector>
#include <memory>

namespace Halley
{
	class CommandLineTool
	{
	public:
		virtual ~CommandLineTool() {}

		static std::vector<std::string> getToolNames();
		static std::unique_ptr<CommandLineTool> getTool(std::string name);

		int runRaw(int argc, char** argv);
		virtual int run(std::vector<std::string> args) = 0;
	};
}
