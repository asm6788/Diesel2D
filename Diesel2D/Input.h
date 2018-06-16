#pragma once
#include <SDL.h>
#include <functional>
#include "Engine.h"
#include "EventSystem\event_system.h"

class Input
{
public:
	Event KeyEvent{};
	Event MouseMotionEvent{};
	Event MouseButtonEvent{};
	Input();
	bool DetectKey();
	~Input();
};

