#pragma once
#include "Component.h"
#include <SDL.h>
#include "EventSystem\event_system.h"
#include "GameObject.h"


class Collision :
	public Component
{
public:
	Event ME_Event{};
	Event Loop_Event{};
	bool IsLoop;
	Collision();
	Collision(GameObject * A, GameObject * B);
	Collision(GameObject * Me);
	void Check(GameObject * Me);
	void Calculate();
	bool Check(GameObject * A, SDL_Rect * B);
	GameObject * A;
	GameObject * B;
	bool Me;
	bool ID;
	~Collision();
};
