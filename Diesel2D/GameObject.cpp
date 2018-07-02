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
	ID = s.Curret.GameObjects.size();
}

GameObject::GameObject(Render renderer, int X, int Y, int w, int h)
{
	SDL_Surface* surface = SDL_GetWindowSurface(renderer.window);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect; rect.x = X;  rect.y = Y; rect.w = w; rect.h = h;
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
	SceneManger s = SceneManger();
	ID = s.Curret.GameObjects.size();
	s.Curret.GameObjects.push_back(this);
}

GameObject::GameObject(Render renderer, Vector2 vector)
{
	SDL_Surface* surface = SDL_GetWindowSurface(renderer.window);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect = vector.ToRect();
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
	SceneManger s = SceneManger();
	ID = s.Curret.GameObjects.size();
	s.Curret.GameObjects.push_back(this);
}

GameObject::GameObject(Render renderer, Vector2 vector, SDL_Surface* surface)
{
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect = vector.ToRect();
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
	SceneManger s = SceneManger();
	ID = s.Curret.GameObjects.size();
	s.Curret.GameObjects.push_back(this);
}


void GameObject::ReqRender(Render renderer)
{
	SDL_DestroyTexture(Texture);
	this->Rect = Rect;
	this->Texture = SDL_CreateTextureFromSurface(renderer.renderer, Surface);
	SceneManger s = SceneManger();
	s.Curret.GameObjects.at(ID) = this;
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
