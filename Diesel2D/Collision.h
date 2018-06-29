#pragma once
#include "Component.h"
#include <SDL.h>
#include "EventSystem\event_system.h"

class Collision :
	public Component
{
private:
	void Loop(SDL_Rect A, SDL_Rect B, bool enable);
public:
	Event Event{};
	bool IsLoop;
	Collision();
	void CollisionLoop(SDL_Rect * A, SDL_Rect * B, bool enable);
	void CollisionLoop(SDL_Rect * Me, bool enable);
	void Loop(SDL_Rect * A, SDL_Rect * B);
	void Loop(SDL_Rect * Me);
	bool Check(SDL_Rect * A, SDL_Rect * B);
	~Collision();
};
