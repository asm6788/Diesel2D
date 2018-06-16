#include <SDL.h>
#include <iostream>
#include "Diesel2D.h"
#include<string>
#include <any>

//Screen dimension constants 
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	EventHandler Key = [](std::any object) {
		SDL_Scancode scan = std::any_cast<SDL_Scancode>(object);
		std::string s = std::to_string(static_cast<int>(scan)) + "\n";
		printf(s.c_str());
	};


	EventHandler MouseMotion = [](std::any object) {
		SDL_MouseMotionEvent scan = std::any_cast<SDL_MouseMotionEvent>(object);
		std::string s = std::to_string(static_cast<int>(scan.x)) + "\n";
		printf(s.c_str());
	};

	EventHandler MouseButton = [](std::any object) {
		SDL_MouseButtonEvent scan = std::any_cast<SDL_MouseButtonEvent>(object);
		std::string s = std::to_string(static_cast<int>(scan.button)) + "\n";
		printf(s.c_str());
	};

	EventHandler Update = [](std::any object) {
		printf("업데이트\n");
	};

	Input input = Input();
	input.KeyEvent += Key;
	input.MouseMotionEvent += MouseMotion;
	input.MouseButtonEvent += MouseButton;
	int posX = 100, posY = 100, width = 1280, height = 720;
	Engine eng = Engine(0,"Scene-0",string("Hello World"), posX, posY, width, height);
	eng.Update += Update;
	Label label = Label(SDL_Color{ 255, 255, 255 }, eng.ren, std::string("d.ttf"),std::string("TEST"), 0, 0, 60, 60);
	input.DetectKey();
	SceneManger s = SceneManger();
	s.Scenes.insert(std::make_pair(SceneID, Scene(SceneID, SceneName)));
	s.LoadScene(s.Curret, );
	//SDL_DestroyTexture(bitmapTex);
	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(win);
	//Image image = Image(eng.ren, "test.png", 0, 0, 60, 60);
	//SDL_Quit();

	return 0;

}
