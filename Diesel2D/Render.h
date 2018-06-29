#pragma once
#include <SDL.h>
#include"EventSystem\event_system.h"
class Render
{
public:
	SDL_Renderer *renderer;
	Render(SDL_Window * win);
	Render();
	~Render();
	void LoppRender();
};
