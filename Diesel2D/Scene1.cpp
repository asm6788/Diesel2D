#include "Scene1.h"
#include "Diesel2D.h"



Scene1::Scene1()
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
	Engine eng = Engine();
	eng.input.KeyEvent += Key;
	eng.input.MouseButtonEvent += MouseButton;
	eng.input.MouseMotionEvent += MouseMotion;
	eng.Update += Update;
	eng.ReqUpdate();
}



Scene1::~Scene1()
{
}
