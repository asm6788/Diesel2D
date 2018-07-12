#include "GameObject.h"
#include<SDL.h>
#include "Render.h"
#include "SceneManger.h"
#include "Vector2.h"
#include <SDL_image.h>
#include <Windows.h>
#include <string>

GameObject::GameObject(SDL_Surface* Surface, SDL_Texture* Texture, SDL_Rect Rect)
{
	this->Surface = Surface;
	this->Texture = Texture;
	this->Rect = Rect;

	SceneManger s = SceneManger();
	ID = s.Curret.GameObjects.size();
	Vector_Rect = &Vector2(Rect);
}

GameObject::GameObject(Render renderer, int X, int Y, int w, int h)
{

	SDL_Surface* surface = SDL_GetWindowSurface(renderer.window);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect; rect.x = X;  rect.y = Y; rect.w = w; rect.h = h;
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
	Vector_Rect = &Vector2(rect);
}

GameObject::GameObject(Render renderer, Vector2 vector)
{

	SDL_Surface* surface = SDL_GetWindowSurface(renderer.window);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect = vector.ToRect();
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
	Vector_Rect = &vector;
}


GameObject::GameObject(Render renderer, Vector2 vector, SDL_Surface* surface)
{

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_Rect rect = vector.ToRect();
	this->Surface = surface;
	this->Texture = texture;
	this->Rect = rect;
	Vector_Rect = &vector;
}


void GameObject::ReqRender(Render renderer)
{
	SDL_DestroyTexture(Texture);
	this->Rect = Rect;
	this->Texture = SDL_CreateTextureFromSurface(renderer.renderer, Surface);
	SceneManger s = SceneManger();

	if (Regsited)
	{
		s.Curret.GameObjects.at(ID) = this;
	}
	else
	{
		Regsited = true;
		ID = s.Curret.GameObjects.size();
		s.Curret.GameObjects.push_back(this);
	}
}

void GameObject::DelRender(Render renderer)
{
	SceneManger s = SceneManger();
	SDL_DestroyTexture(Texture);
	SDL_FreeSurface(Surface);
	if (Regsited)
	{
		Regsited = false;
		s.Curret.GameObjects.erase(s.Curret.GameObjects.begin() + ID);
	}
}



void GameObject::ImageLoad(std::string file)
{
	Surface = IMG_Load(ExePath().append("\\").append(file.c_str()).c_str());

}

std::string GameObject::ExePath()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}

void GameObject::Translate(Vector2 vector)
{
	Rect = (Vector2(Rect) + vector).ToRect();
}

bool GameObject::InCamera(int ScrennW, int ScrennH)
{
	if (Rect.x - Rect.w < 0 || ( Rect.y + Rect.h > ScrennH || Rect.y - Rect.h < 0) || Rect.x + Rect.w > ScrennW)
	{
		return false; //È­¸é¹Û
	}
	return true;
}



GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

bool GameObject::operator!=(GameObject other)
{
	if (Surface == other.Surface || Texture == other.Texture || &Rect == &other.Rect)
	{
		return false;
	}
	return true;
}
