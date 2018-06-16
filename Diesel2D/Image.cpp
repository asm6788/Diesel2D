#include "Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Render.h"
#include "SceneManger.h"
#include <string>

using namespace std;
Image::Image(Render renderer, string file,int X, int Y, int w, int h)
{
	SDL_Surface* surface = IMG_Load(UI::path.append(file.c_str()).c_str());
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer.renderer, surface); 
	SDL_Rect Message_rect; Message_rect.x = X;  Message_rect.y = Y; Message_rect.w = w; Message_rect.h = h;
	SDL_RenderCopy(renderer.renderer, Message, NULL, &Message_rect);

	SceneManger s = SceneManger();
	s.Curret.GameObjects.push_back(GameObject(surface, Message, Message_rect));
}


Image::~Image()
{
}
