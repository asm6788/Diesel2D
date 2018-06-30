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
	};

	EventHandler CollisionEvent = [](std::any object) {
		printf("Ãæµ¹ÇÔ! Äâ±¤ \n");
	};

	Audio audio = Audio("soviet-anthem.mp3", "Kim.mp3");
	/*audio.Play(false);
	audio.PlayEffect(100);*/
	Engine eng = Engine();
	eng.input.KeyEvent += Key;
	eng.input.MouseButtonEvent += MouseButton;
	eng.input.MouseMotionEvent += MouseMotion;
	eng.Update += Update;
	Image img = Image(eng.ren, "test.png", 10, 10, 100, 100);
	Image img1 = Image(eng.ren, "test.png", 10, 10, 100, 100);
	Collision col = Collision();
	col.Event += CollisionEvent;
	col.CollisionLoop(&img.Rect, true);
	GameObject go = GameObject(eng.ren,Vector2(300, 300, 100, 100));
	int res = SDL_FillRect(go.Surface, NULL, SDL_MapRGB(go.Surface->format, 255, 255, 255));
	go.ReqRender(eng.ren);
	eng.ReqUpdate();
}

Scene1::~Scene1()
{
}