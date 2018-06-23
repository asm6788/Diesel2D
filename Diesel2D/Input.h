#pragma once
#include <SDL.h>
#include <functional>
#include "EventSystem\event_system.h"

class Input
{
private:
	bool CanInput;
public:
	Event KeyEvent{};
	Event MouseMotionEvent{};
	Event MouseButtonEvent{};
	Input();
	void DetectKey();
	~Input();
};

