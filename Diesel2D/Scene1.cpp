#include "Scene1.h"
#include "Diesel2D.h"
#include<string>
#include<iostream>

using namespace std;

ProcessLUA lua = ProcessLUA("script\\test.lua");
GameObject go;
Engine eng = Engine();
Scene1::Scene1()
{
	int result = lua.state["luaAdd"](1, 2);
	EventHandler Key = [](std::any object) {
		SDL_Scancode scan = std::any_cast<SDL_Scancode>(object);
		int KeyNum = static_cast<int>(scan);
		switch (KeyNum)
		{
		case SDL_SCANCODE_W:
			go.Rect = (Vector2(go.Rect) + Vector2(0, -10, 0, 0)).ToRect();
			break;
		case SDL_SCANCODE_A:
			go.Rect = (Vector2(go.Rect) + Vector2(-10, 0, 0, 0)).ToRect();
			break;
		case SDL_SCANCODE_S:
			go.Rect = (Vector2(go.Rect) + Vector2(0, 10, 0, 0)).ToRect();
			break;
		case SDL_SCANCODE_D:
			go.Rect = (Vector2(go.Rect) + Vector2(10, 0, 0, 0)).ToRect();
			break;
		default:
			break;
		}
		
	};

	EventHandler MouseMotion = [](std::any object) {
	/*	SDL_MouseMotionEvent scan = std::any_cast<SDL_MouseMotionEvent>(object);
		std::string s = std::to_string(static_cast<int>(scan.x)) + "\n";
		printf(s.c_str());*/
	};

	EventHandler MouseButton = [](std::any object) {
	/*	SDL_MouseButtonEvent scan = std::any_cast<SDL_MouseButtonEvent>(object);
		std::string s = std::to_string(static_cast<int>(scan.button)) + "\n";
		printf(s.c_str());*/
	};


	EventHandler Update = [](std::any object) {

	};

	EventHandler CollisionEvent = [](std::any object) {
		printf("Ãæµ¹ÇÔ! Äâ±¤ \n");
	};

	Audio audio = Audio("soviet-anthem.mp3", "Kim.mp3");
	/*audio.Play(false);
	audio.PlayEffect(100);*/

	eng.input.KeyEvent += Key;
	eng.input.MouseButtonEvent += MouseButton;
	eng.input.MouseMotionEvent += MouseMotion;
	eng.Update += Update;
	//Image img = Image(eng.ren, "test.png", 10, 10, 100, 100);
	//Image img1 = Image(eng.ren, "test.png", 10, 10, 100, 100);
	go = GameObject(eng.ren, Vector2(300, 300, 100, 100));
	SDL_FillRect(go.Surface, NULL, SDL_MapRGB(go.Surface->format, 255, 255, 255));

	GameObject go2 = GameObject(eng.ren, Vector2(100, 100, 50, 50));

	Collision col = Collision(&go ,&go2);
	col.Loop_Event+= CollisionEvent;
	col.ID = eng.Collisions.size();
	eng.Collisions.push_back(&col);
	go.ReqRender(eng.ren);
	eng.ReqUpdate();
}

Scene1::~Scene1()
{
}