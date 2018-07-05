#include "Engine.h"
#include<thread>
#include<iostream>
#include<SDL.h>
#include "Render.h"
#include"Input.h"
#include"SceneManger.h"
#include "Collision.h"
#include <vector>

using namespace std;

bool Engine::CanInput;
Render Engine::ren;
Input Engine::input = Input();
vector<Collision *> Engine::Collisions;

Engine::Engine(int SceneID, string SceneName, string title, int posX, int posY, int width, int height)
{
	SDL_Init(SDL_INIT_VIDEO);
	SceneManger s = SceneManger();
	s.Scenes.insert(std::make_pair(SceneID, Scene(SceneID, SceneName)));
	s.Curret = Scene(SceneID, SceneName);
	SDL_Window * win = SDL_CreateWindow(title.c_str(), posX, posY, width, height, 0);
	ren = Render(win);
}

Engine::Engine()
{
}

Uint64 NOW;
Uint64 LAST = 0;
double Engine::deltaTime = 0;
float fps;

void Engine::ReqInput()
{
	CanInput = true;
	input.DetectKey();
}

void Engine::EndInput()
{
	CanInput = false;
}

void Engine::ReqUpdate()
{
	while (true)
	{
		if (CanInput) { break; }
		Update(NULL);
		input.DetectKey();
		ren.LoopRender();
		for each(Collision* col in Collisions)
		{
			col->Calculate();
		}
		deltaTime = ((double)(SDL_GetTicks() - LAST)) / 1000;
		fps = 1000.0f / (float)(SDL_GetTicks() - LAST);
		LAST = SDL_GetTicks();

		if (deltaTime > 0.1)
			deltaTime = 0.1;

		if (0.025 <deltaTime < 0.06)
			SDL_Delay((0.025 - deltaTime) * 1000);

	}
}

void Engine::TEST()
{
	printf("I am Working!!");
}

Engine::~Engine()
{
}