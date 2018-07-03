#include "Render.h"
#include <SDL.h>
#include <chrono>
#include <thread>
#include"EventSystem\event_system.h"
#include "SceneManger.h"
#include<string>

SDL_Renderer * Render::renderer;
SDL_Window * Render::window;
SDL_Surface * Render::surface;
Render::Render(SDL_Window * win)
{
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	window = win;
	surface = SDL_GetWindowSurface(win);
}

Render::Render()
{
}

Render::~Render()
{
}

void Render::LoopRender()
{

	SceneManger s = SceneManger();
	//printf("·»´õ¸µÁß..");
	SDL_RenderClear(renderer);
	for each(GameObject* go in s.Curret.GameObjects)
	{
		SDL_RenderCopy(renderer, go->Texture, NULL, &go->Rect);
	}
	/*for each(UI* ui in s.Curret.UIs)
	{
		SDL_RenderCopy(renderer, ui->Texture, NULL, &ui->Rect);
	}*/
	SDL_RenderPresent(renderer);
	SDL_Delay(1000 / 60); // 60FPS
}
