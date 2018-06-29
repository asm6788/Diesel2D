#define _USE_MATH_DEFINES

#include "Vector2.h"
#include <math.h>
#include <SDL.h>
#include "SceneManger.h"
#include "GameObject.h"

Vector2::Vector2(double _x, double _y, double _w, double _h)
{
	x = _x;
	y = _y;
	w = _y;
	h = _h;
}

Vector2::Vector2(SDL_Rect rect)
{
	x = rect.x; y = rect.y; w = rect.w; h = rect.h;
}

Vector2::Vector2()
{
}

Vector2 Vector2::operator+(Vector2 other)
{
	return Vector2(x + other.x, y + other.y, w + other.w, h + other.h);
}

Vector2 Vector2::operator-(Vector2 other)
{
	return Vector2(x - other.x, y - other.y, w - other.w, h - other.h);
}

Vector2 Vector2::operator*(int other)
{
	return Vector2(x * other, y * other, w * other, h * other);
}

Vector2 Vector2::operator/(int other)
{
	return Vector2(x / other, y / other, w / other, h / other);
}

Vector2 Vector2::operator*(double other)
{
	return Vector2(x * other, y * other, w * other, h * other);
}

Vector2 Vector2::operator/(double other)
{
	return Vector2(x / other, y / other, w / other, h / other);
}

void Vector2::operator+=(Vector2 other)
{
	x += other.x;
	y += other.y;
	w += other.w;
	h += other.h;
}

void Vector2::operator-=(Vector2 other)
{
	x -= other.x;
	y -= other.y;
	w -= other.w;
	h -= other.h;
}

void Vector2::operator*=(int other)
{
	x *= other;
	y *= other;
	w *= other;
	h *= other;
}

void Vector2::operator/=(int other)
{
	x /= other;
	y /= other;
	w /= other;
	h /= other;
}

void Vector2::operator*=(double other)
{
	x *= other;
	y *= other;
	w *= other;
	h *= other;
}

void Vector2::operator/=(double other)
{
	x /= other;
	y /= other;
	w /= other;
	h /= other;
}

bool Vector2::operator==(Vector2 other)
{
	return (x == other.x && y == other.y);
}

bool Vector2::operator!=(Vector2 other)
{
	return (x != other.x && y != other.y);
}
double Vector2::DistanceTo(Vector2 other)
{
	double dx = x - other.x;
	double dy = y - other.y;

	return sqrt(dx * dx + dy * dy);
}

std::pair <double, GameObject> Vector2::NearObject(SDL_Rect * exclude)
{
	std::pair <double, GameObject> Temp = std::make_pair(100000000, GameObject());
	SceneManger s = SceneManger();
	for each(GameObject go in s.Curret.GameObjects)
	{
		double distance = this->DistanceTo(Vector2(go.Rect));
		if (distance <= Temp.first && &go.Rect != exclude)
		{
			Temp = std::make_pair(distance, go);
		}
	}

	return Temp;
}


std::pair <double, GameObject> Vector2::NearObject(GameObject exclude)
{
	std::pair <double, GameObject> Temp = std::make_pair(100000000, GameObject());
	SceneManger s = SceneManger();
	for each(GameObject go in s.Curret.GameObjects)
	{
		double distance = this->DistanceTo(Vector2(go.Rect));
		if (distance <= Temp.first && go != exclude )
		{
			Temp = std::make_pair(distance, go);
		}
	}

	return Temp;
}


float Vector2::LookRotation()
{
	double angle = atan2(y, x);
	angle = 90 + angle / M_PI * 180;
	if (angle < 0)
		angle += 360;
	return angle;
}

Vector2 Vector2::Normalize()
{
	double d = DistanceTo(Vector2());

	if (d == 0)
		return Vector2();

	return Vector2(x / d, y / d, w / d, h / d);
}

Vector2 Vector2::Rotate(double angle)
{
	double d = DistanceTo(Vector2());

	double originalAngle = LookRotation();

	return Vector2(cos((angle + originalAngle - 90) / 180 * M_PI), sin((angle + originalAngle - 90) / 180 * M_PI), w, h) * d;
}

SDL_Rect Vector2::ToRect()
{
	SDL_Rect rect; rect.x = x;  rect.y = y; rect.w = w; rect.h = h;
	return rect;
}