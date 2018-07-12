#pragma once

#include <SDL.h>
#include "GameObject.h"
#include "Render.h"

class Vector2
{
public:
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
	Vector2();
	Vector2(int x, int y, int w, int h);
	Vector2(SDL_Rect rect);
	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
	Vector2 operator*(int other);
	Vector2 operator/(int other);
	void operator+=(Vector2 other);
	void operator-=(Vector2 other);
	void operator*=(int other);
	void operator/=(int other);
	bool operator==(Vector2 other);
	bool operator!=(Vector2 other);
	int DistanceTo(Vector2 other);
	std::pair<int, GameObject *> NearObject(SDL_Rect * exclude);
	std::pair<int, GameObject *> NearObject(GameObject* exclude);
	Vector2 Normalize();
	SDL_Rect ToRect();
	float LookRotation();
	Vector2 Rotate(int angle);
};