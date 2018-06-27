#include "ProcessLUA.h"
#include <string>
#include <windows.h>
#include <sol.hpp>
using namespace std;

ProcessLUA::ProcessLUA()
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	lua.script_file("C:\\Users\\asm67\\source\\repos\\Diesel2D\\x64\\Debug\\script\\test.lua");
	int i = lua["luaAdd"](1, 10);
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