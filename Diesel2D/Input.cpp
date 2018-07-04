#include "Input.h"
#include <SDL.h>
#include<iostream>
#include <functional>
#include "EventSystem\event_system.h"
#include<thread>

const Uint8 *keystates;

Input::Input()
{
	keystates = SDL_GetKeyboardState(NULL);
}

void Input::DetectKey()
{
	SDL_Event event;
	if(SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			KeyEvent(event.key.keysym.scancode);
		}
		else if (event.type == SDL_QUIT)
		{
			SDL_Quit();
			std::exit(0);
		}
		else if (event.type == SDL_MOUSEMOTION)
		{
			MouseMotionEvent(event.motion);
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			MouseButtonEvent(event.button);
		}
	}
}

Input::~Input()
{
}