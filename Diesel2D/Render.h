#pragma once
#include <SDL.h>
#include"EventSystem\event_system.h"

class Render
{
public:
	static SDL_Renderer *renderer;
	static SDL_Window * window;
	static SDL_Surface * surface;
	Render(SDL_Window * win);
	Render();
	~Render();
	void LoopRender();
};
