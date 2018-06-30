#include "GameObject.h"
#include<SDL.h>
#include "Render.h"
#include "SceneManger.h"
#include "Vector2.h"

GameObject::GameObject(SDL_Surface* Surface, SDL_Texture* Texture, SDL_Rect Rect)
{
	this->Surface = Surface;
	this->Texture = Texture;
	this->Rect = Rect;

	SceneManger s = SceneManger();
	s.Curret.GameObjects.push_back(this);
}

GameObject::GameObject(Render renderer, int X, int Y, int w, int h)
{
	SDL_Surface* surface = SDL_GetWindowSurface(renderer.window);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect; rect.x = X;  rect.y = Y; rect.w = w; rect.h = h;
	SceneManger s = SceneManger();
	s.Curret.UIs.push_back(&UI(surface, texture, rect));
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
}

GameObject::GameObject(Render renderer, Vector2 vector)
{
	SDL_Surface* surface = SDL_GetWindowSurface(renderer.window);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect = vector.ToRect();
	SceneManger s = SceneManger();
	s.Curret.UIs.push_back(&UI(surface, texture, rect));
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
}

GameObject::GameObject(Render renderer, Vector2 vector, SDL_Surface* surface)
{
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect = vector.ToRect();
	SceneManger s = SceneManger();
	s.Curret.UIs.push_back(&UI(surface, texture, rect));
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
}


void GameObject::ReqRender(Render renderer)
{
	this->Texture = SDL_CreateTextureFromSurface(renderer.renderer, Surface);
	SDL_RenderCopy(renderer.renderer,Texture, NULL, &Rect);
}

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

bool GameObject::operator!=(GameObject other)
{
	if (Surface == other.Surface || Texture == other.Texture || &Rect == &other.Rect)
	{
		return false;
	}
	return true;
}
