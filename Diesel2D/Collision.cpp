#include "Collision.h"
#include <SDL.h>
#include<thread>
#include "Vector2.h"

using namespace std;


Collision::Collision()
{
}

void Collision::CollisionLoop(SDL_Rect * A, SDL_Rect * B, bool enable)
{
	IsLoop = enable;
	thread TH_loop([A, B, this] {Loop(A, B); });
	TH_loop.detach();
}
void Collision::Loop(SDL_Rect * A, SDL_Rect * B)
{
	while (true)
	{
		if (IsLoop)
		{
			if(Check(A, B))
			{
				Event(NULL);
			}
		}
		else
		{
			break;
		}

		SDL_Delay(100 / 6);
	}
}

void Collision::CollisionLoop(SDL_Rect * Me, bool enable)
{
	IsLoop = enable;
	thread TH_loop([Me, this] {Loop(Me); });
	TH_loop.detach();
}

void Collision::Loop(SDL_Rect * Me)
{
	while (true)
	{
		SDL_Rect Rect_Me = *Me;
		SDL_Rect Near = Vector2(Rect_Me).NearObject(&Rect_Me).second.Rect;
		if (IsLoop)
		{
			if(Check(Me, &Near))
			{
				Event(NULL);
			}
		}
		else
		{
			break;
		}

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