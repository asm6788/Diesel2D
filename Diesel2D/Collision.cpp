#include "Collision.h"
#include <SDL.h>
#include<thread>

using namespace std;
Collision::Collision()
{
}

void Collision::CollisionLoop(SDL_Rect * A, SDL_Rect * B, bool enable)
{
	IsLoop = enable;
	thread TH_loop([A, B,this] {Loop(A, B); });
	TH_loop.detach();
}

void Collision::Loop(SDL_Rect * A, SDL_Rect * B)
{
	while (true)
	{
		if (IsLoop)
		{	Check(A, B);	}
		else
		{	break;	}

		SDL_Delay(100 / 6);
	}
}


bool Collision::Check(SDL_Rect * A, SDL_Rect * B)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	leftA = A->x;
	rightA = A->x + A->w;
	topA = A->y;
	bottomA = A->y + A->h;
	leftB = B->x;
	rightB = B->x + B->w;
	topB = B->y;
	bottomB = B->y + B->h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}
	return true;
}

Collision::~Collision()
{
}
