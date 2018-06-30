#pragma once
#include "Vector2.h"
#include <SDL.h>
#include "GameObject.h"

class Vector2
{
public:
	double x = 0;
	double y = 0;
	double w = 0;
	double h = 0;
	Vector2();
	Vector2(double x, double y, double w, double h);
	Vector2(SDL_Rect rect);
	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
	Vector2 operator*(int other);
	Vector2 operator/(int other);
	Vector2 operator*(double other);
	Vector2 operator/(double other);
	void operator+=(Vector2 other);
	void operator-=(Vector2 other);
	void operator*=(int other);
	void operator/=(int other);
	void operator*=(double other);
	void operator/=(double other);
	bool operator==(Vector2 other);
	bool operator!=(Vector2 other);
	double DistanceTo(Vector2 other);
	std::pair<double, GameObject *> NearObject(SDL_Rect * exclude);
	std::pair<double, GameObject *> NearObject(GameObject* exclude);
	float LookRotation();
	Vector2 Normalize();
	Vector2 Rotate(double angle);
	SDL_Rect ToRect();
};