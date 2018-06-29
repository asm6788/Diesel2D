#pragma once
#include <SDL.h>
class GameObject
{
public:
	SDL_Surface* Surface;
	SDL_Texture* Texture;
	SDL_Rect Rect;
	GameObject(SDL_Surface * Surface, SDL_Texture * Texture, SDL_Rect Rect);
	GameObject();
	~GameObject();
	bool operator!=(GameObject other);
};
