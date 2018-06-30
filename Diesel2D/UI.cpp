#include "UI.h"
#include<string>
#include <windows.h>
#include "GameObject.h"

using namespace std;
string path;
UI::UI()
{
	path = UI::ExePath().append("\\");

}

UI::UI(SDL_Surface* Surface, SDL_Texture* Texture, SDL_Rect Rect)
{
	this->Surface = Surface;
	this->Texture = Texture;
	this->Rect = Rect;
}


UI::~UI()
{
}

string UI::ExePath()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}