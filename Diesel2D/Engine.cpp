#include "Engine.h"
#include<thread>
#include<iostream>
#include<SDL.h>
#include "Render.h"
#include"Input.h"
#include"SceneManger.h"
using namespace std;

bool Engine::CanInput;
Render Engine::ren;
Input Engine::input = Input();
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
		ren.LoppRender();
		SDL_Delay(100 / 6);
	}
}

void Engine::TEST()
{
	printf("I am Working!!");
}

Engine::~Engine()
{
}