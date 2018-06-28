#pragma once
#include "Component.h"
#include <SDL.h>

class Collision :
	public Component
{
public:
	Collision();
	bool Check(SDL_Rect A, SDL_Rect B);
	~Collision();
};

