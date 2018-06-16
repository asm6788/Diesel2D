#include "Input.h"
#include <SDL.h>
#include<iostream>
#include <functional>
#include "Engine.h"
#include "EventSystem\event_system.h"

const Uint8 *keystates;

Input::Input()
{
	SDL_Event event;
	keystates = SDL_GetKeyboardState(NULL);
}

bool Input::DetectKey()
{
	while (true)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				KeyEvent(event.key.keysym.scancode);
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
		SDL_Delay(100 / 6);
	}
}

Input::~Input()
{
}
