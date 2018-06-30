#pragma once
#include <string>
#include <SDL.h>

class UI
{
public:
	SDL_Surface* Surface;
	SDL_Texture* Texture;
	SDL_Rect Rect;

	std::string path;
	UI();
	UI(SDL_Surface* Surface, SDL_Texture* Texture, SDL_Rect Rect);
	~UI();
	std::string ExePath();
};
