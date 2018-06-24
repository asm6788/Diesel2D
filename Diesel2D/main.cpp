#include <SDL.h>
#include <iostream>
#include "Diesel2D.h"
#include<string>
#include <any>
#include "Scene1.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	int posX = 100, posY = 100, width = 1280, height = 720;
	Engine eng = Engine(0, "Init", string("Hello World"), posX, posY, width, height);
	/*Label label = Label(SDL_Color{ 255, 255, 255 }, eng.ren, std::string("d.ttf"),std::string("TEST"), 0, 0, 60, 60);*/
	SceneManger s = SceneManger();
	Scene scene = Scene(1, "Scene-1");
	s.Scenes.insert(std::make_pair(1, scene));
	s.LoadScene(s.Curret, scene);
	Scene1();

	//SDL_DestroyTexture(bitmapTex);
	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(win);
	//SDL_Quit();
	return 0;
}