#include "Scene1.h"
#include "Diesel2D.h"
#include<string>
#include<iostream>

using namespace std;

ProcessLUA lua = ProcessLUA("script\\test.lua");
GameObject Me;
std::vector<GameObject> Bullets;
Vector2 BulletMove;
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
			Me.Translate(Vector2(0, -10, 0, 0));
			break;
		case SDL_SCANCODE_A:
			Me.Translate(Vector2(-10, 0, 0, 0));
			break;
		case SDL_SCANCODE_S:
			Me.Translate(Vector2(0, 10, 0, 0));
			break;
		case SDL_SCANCODE_D:
			Me.Translate(Vector2(10, 0, 0, 0));
			break;
		case SDL_SCANCODE_Q:
			Bullets.push_back(GameObject(eng.ren, Vector2(570, 580, 1, 50)));
			Bullets.back().ReqRender(eng.ren);
			BulletMove = Vector2(-10, -10, 0, 0);
			break;
		case SDL_SCANCODE_E:
			Bullets.push_back(GameObject(eng.ren, Vector2(570, 580, 1, 50)));
			Bullets.back().ReqRender(eng.ren);
			BulletMove = Vector2(10, -10, 0, 0);
			break;
		case SDL_SCANCODE_2:
			Bullets.push_back(GameObject(eng.ren, Vector2(570, 580, 1, 50)));
			Bullets.back().ReqRender(eng.ren);
			BulletMove = Vector2(0, -10, 0, 0);
			break;
		case SDL_SCANCODE_SPACE:
			Bullets.push_back(GameObject(eng.ren, Vector2(570, 580, 1, 50)));
			Bullets.back().ReqRender(eng.ren);
			BulletMove = Vector2(0, 10, 0, 0);
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
		/*for each(GameObject Bullet in Bullets)
		{
			if (!Bullet.InCamera(1280, 720))
			{
				BulletMove = Vector2();
				Bullet.DelRender(eng.ren);
				Bullet.Rect = Vector2(570, 580, 1, 50).ToRect();
			}
		}*/
	};

	EventHandler CollisionEvent = [](std::any object) {
		printf("Ãæµ¹ÇÔ! Äâ±¤ \n");
	};

	Audio audio = Audio("soviet-anthem.mp3", "Kim.mp3");
	/*audio.Play(false);
	audio.PlayEffect(100);*/

	eng.input.KeyEvent += Key;
	//eng.input.MouseButtonEvent += MouseButton;
	//eng.input.MouseMotionEvent += MouseMotion;
	eng.Update += Update;
	//Image img = Image(eng.ren, "test.png", 10, 10, 100, 100);
	//Image img1 = Image(eng.ren, "test.png", 10, 10, 100, 100);
	Me = GameObject(eng.ren, Vector2(570, 630, 150, 65));
	Me.ImageLoad("GameData\\Image\\Character\\SD.png");

	/*Bullet.ADDGameObject(eng.ren, Vector2(570, 580, 1, 50));
	SDL_FillRect(Bullet.Surface, NULL, SDL_MapRGB(Bullet.Surface->format, 255, 0, 0));
*/

/*Collision col = Collision(&go ,&go2);
col.Loop_Event+= CollisionEvent;
col.ID = eng.Collisions.size();
eng.Collisions.push_back(&col);*/
	Me.ReqRender(eng.ren);
	eng.ReqUpdate();
}

Scene1::~Scene1()
{
}