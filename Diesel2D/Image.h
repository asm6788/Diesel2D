#pragma once
#include"UI.h"
#include "Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Render.h"
#include <string>
using namespace std;
class Image :
	public UI
{
public:
	
	Image(Render renderer, string file, int X, int Y, int w, int h);

	~Image();
};

