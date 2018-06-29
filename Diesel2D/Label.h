#pragma once
#include "Label.h"
#include "Render.h"
#include <SDL.h>
#include<SDL_ttf.h>
#include<string>
#include <windows.h>
#include"UI.h"
#include"Vector2.h"

using namespace std;

class Label :
	public UI
{
public:
	Label(SDL_Color color, Render renderer, std::string font, std::string text, int X, int Y, int w, int h);
	Label(SDL_Color color, Render renderer, string font, string text, Vector2 postion);
	~Label();
};
