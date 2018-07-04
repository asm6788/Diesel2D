#include "Collision.h"
#include <SDL.h>
#include "Vector2.h"
#include "GameObject.h"
#include "EventSystem\event_system.h"

using namespace std;


Collision::Collision()
{
}

 Collision::Collision(GameObject * A, GameObject * B)
{
	this->A = A;
	this->B = B;
}

Collision::Collision(GameObject * Me)
{
	this->A = Me;
	this->Me = true;
}


void Collision::Calculate()
{
	if(Me)
	{ 
		Check(A);
	}
	else
	{
		if (Check(A, &B->Rect))
		{
			Loop_Event(std::make_pair(A, B));
		}
	}
}

void Collision::Check(GameObject * Me)
{
	if (!Me) { cerr << "Can not be used with Me boolean is false" << endl; }
	SDL_Rect Rect_Me = Me->Rect;
	SDL_Rect Near = Vector2(Rect_Me).NearObject(&Rect_Me).second->Rect;
	if (Check(Me, &Near))
	{
		ME_Event(Me);
	}
}

bool Collision::Check(GameObject * A, SDL_Rect * B)
{
	if (Me) { cerr << "Can not be used with Me boolean is true" << endl;}
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	leftA = A->Rect.x;
	rightA = A->Rect.x + A->Rect.w;
	topA = A->Rect.y;
	bottomA = A->Rect.y + A->Rect.h;
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