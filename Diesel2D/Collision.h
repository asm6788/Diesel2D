#pragma once
#include "Component.h"
#include <SDL.h>

class Collision :
	public Component
{
private:
	void Loop(SDL_Rect A, SDL_Rect B, bool enable);
public:
	bool IsLoop;
	Collision();
	void CollisionLoop(SDL_Rect * A, SDL_Rect * B, bool enable);
	void Loop(SDL_Rect * A, SDL_Rect * B);
	bool Check(SDL_Rect * A, SDL_Rect * B);
	~Collision();
};

