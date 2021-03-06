#include "Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Render.h"
#include "SceneManger.h"
#include <string>
#include "Vector2.h"

using namespace std;
Image::Image(Render renderer, string file, int X, int Y, int w, int h)
{
	SDL_Surface* surface = IMG_Load(UI::path.append(file.c_str()).c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect; rect.x = X;  rect.y = Y; rect.w = w; rect.h = h;
	SDL_RenderCopy(renderer.renderer, texture, NULL, &rect);
	SceneManger s = SceneManger();
	s.Curret.UIs.push_back(&UI(surface, texture, rect));
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
}

Image::Image(Render renderer, string file, Vector2 postion)
{
	SDL_Surface* surface = IMG_Load(UI::path.append(file.c_str()).c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect = postion.ToRect();
	SDL_RenderCopy(renderer.renderer, texture, NULL, &rect);
	SceneManger s = SceneManger();
	s.Curret.UIs.push_back(&UI(surface, texture, rect));
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
}

Image::~Image()
{
}