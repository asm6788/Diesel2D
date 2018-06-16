#include "GameObject.h"
#include<SDL.h>


GameObject::GameObject(SDL_Surface* Surface,SDL_Texture* Texture,SDL_Rect Rect)
{
	this->Surface = Surface;
	this->Texture = Texture;
	this->Rect = Rect;
}


GameObject::~GameObject()
{
	
}
