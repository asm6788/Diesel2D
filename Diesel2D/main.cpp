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
	Engine eng = Engine(0, "Init", string("SD-Chan!"), posX, posY, width, height);
	printf("엔진 초기화 완료");
	/*Label label = Label(SDL_Color{ 255, 255, 255 }, eng.ren, std::string("d.ttf"),std::string("TEST"), 0, 0, 60, 60);*/
	SceneManger s = SceneManger();
	Scene scene = Scene(1, "Scene-1");
	s.Scenes.insert(std::make_pair(1, scene));
	s.LoadScene(s.Curret, scene);
	Scene1();
	return 0;
}