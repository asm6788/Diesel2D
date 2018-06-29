#include "Scene1.h"
#include "Diesel2D.h"
#include<string>
#include<iostream>

using namespace std;

ProcessLUA lua = ProcessLUA("script\\test.lua");

Scene1::Scene1()
{
	int result = lua.state["luaAdd"](1, 2);
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
		int result = lua.state["luaAdd"](1, 2);
		
	};
	Audio audio = Audio("soviet-anthem.mp3","Kim.mp3");
	/*audio.Play(false);
	audio.PlayEffect(100);*/
	Engine eng = Engine();
	eng.input.KeyEvent += Key;
	eng.input.MouseButtonEvent += MouseButton;
	eng.input.MouseMotionEvent += MouseMotion;
	eng.Update += Update;
	Image img = Image(eng.ren, "test.png", 10, 10, 10, 10);
	Image img1 = Image(eng.ren, "test.png", 10, 10, 10, 10);
	Collision col = Collision();
	col.CollisionLoop(&img.Rect, &img1.Rect,true);
	eng.ReqUpdate();
}

Scene1::~Scene1()
{
}