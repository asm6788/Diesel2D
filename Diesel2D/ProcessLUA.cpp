#include "ProcessLUA.h"
#include <string>
#include <windows.h>
#include <sol.hpp>
using namespace std;

ProcessLUA::ProcessLUA(string file)
{
	state.open_libraries(sol::lib::base);
	state.script_file(ExePath().append("\\").append(file.c_str()).c_str());
}
ProcessLUA::ProcessLUA(const ProcessLUA &)
{
	
}

string ProcessLUA::ExePath()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

ProcessLUA::~ProcessLUA()
{
}