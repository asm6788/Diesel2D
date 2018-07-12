#pragma once
#include "GameObject.h"
#include <SDL.h>
#include "Render.h"
#include <Windows.h>

class Vector2;

class GameObject
{
public:
	SDL_Surface* Surface;
	SDL_Texture* Texture;
	SDL_Rect Rect;
	Vector2* Vector_Rect;
	int ID;
	bool Regsited = false;
	GameObject(SDL_Surface * Surface, SDL_Texture * Texture, SDL_Rect Rect);
	GameObject(Render renderer, int X, int Y, int w, int h);
	GameObject(Render renderer, Vector2 vector);
	GameObject(Render renderer, Vector2 vector, SDL_Surface * surface);
	void ReqRender(Render renderer);
	void DelRender(Render renderer);
	void ImageLoad(std::string file);
	std::string ExePath();
	void Translate(Vector2 vector);
	bool InCamera(int ScrennW, int ScrennH);
	GameObject();
	~GameObject();
	bool operator!=(GameObject other);
};
