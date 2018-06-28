#pragma once
#include<string>
#include <windows.h>
#include <sol.hpp>
using namespace std;
class ProcessLUA
{
public:
	sol::state state;
	ProcessLUA(string file);
	ProcessLUA(const ProcessLUA &);
	string ExePath();
	~ProcessLUA();
};

