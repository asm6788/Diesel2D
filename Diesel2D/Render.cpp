#include "Render.h"
#include <SDL.h>
#include <chrono>
#include <thread>
#include"EventSystem\event_system.h"

SDL_Renderer *renderer;
Render::Render(SDL_Window * win)
{
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
}

Render::Render()
{

}

Render::~Render()
{
}

void Render::LoppRender()
{
	while (true) {
		SDL_RenderPresent(renderer);
		SDL_Delay(1000 / 60); // 60FPS
	}
}