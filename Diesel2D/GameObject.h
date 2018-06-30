#pragma once
#include "GameObject.h"
#include <SDL.h>
#include "Render.h"

class Vector2;
class GameObject
{
public:
	SDL_Surface* Surface;
	SDL_Texture* Texture;
	SDL_Rect Rect;

	GameObject(SDL_Surface * Surface, SDL_Texture * Texture, SDL_Rect Rect);
	GameObject(Render renderer, int X, int Y, int w, int h);
	GameObject(Render renderer, Vector2 vector);
	GameObject(Render renderer, Vector2 vector, SDL_Surface * surface);
	void ReqRender(Render renderer);
	GameObject();
	~GameObject();
	bool operator!=(GameObject other);
};
