#include "Label.h"
#include "Render.h"
#include "SceneManger.h"
#include <SDL.h>
#include<SDL_ttf.h>
#include<string>
#include <windows.h>
#include "Vector2.h"

using namespace std;

Label::Label(SDL_Color color, Render renderer, string font, string text, int X, int Y, int w, int h)
{
	TTF_Init();
	string fontlocal = UI::path.append(font.c_str());
	TTF_Font* Font = TTF_OpenFont(fontlocal.c_str(), 24); //this opens a font style and sets a size
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Font, text.c_str(), color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer.renderer, surfaceMessage); //now you can convert it into a texture
	SDL_Rect Message_rect; Message_rect.x = X;  Message_rect.y = Y; Message_rect.w = w; Message_rect.h = h;
	SDL_RenderCopy(renderer.renderer, Message, NULL, &Message_rect);

	SceneManger s = SceneManger();
	s.Curret.GameObjects.push_back(GameObject(surfaceMessage, Message, Message_rect));

	this->Surface = surfaceMessage;
	this->Texture = Message;
	this->Rect = Message_rect;
}

Label::Label(SDL_Color color, Render renderer, string font, string text, Vector2 postion)
{
	TTF_Init();
	string fontlocal = UI::path.append(font.c_str());
	TTF_Font* Font = TTF_OpenFont(fontlocal.c_str(), 24); //this opens a font style and sets a size
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Font, text.c_str(), color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer.renderer, surfaceMessage); //now you can convert it into a texture
	SDL_Rect Message_rect = postion.ToRect();
	SDL_RenderCopy(renderer.renderer, Message, NULL, &Message_rect);

	SceneManger s = SceneManger();
	s.Curret.GameObjects.push_back(GameObject(surfaceMessage, Message, Message_rect));

	this->Surface = surfaceMessage;
	this->Texture = Message;
	this->Rect = Message_rect;
}

Label::~Label()
{
}