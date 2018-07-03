#pragma once
#include<string>
#include"Render.h"
#include <functional>
#include "EventSystem\event_system.h"
#include"Input.h"

using namespace std;
class Engine
{
public:
	static bool CanInput;
	static Render ren;
	static Input input;
	static double deltaTime;
	Event Update{};
	~Engine();
	Engine(int SceneID, string Scene, string title, int posX, int posY, int width, int height);
	Engine();
	void ReqInput();
	void EndInput();
	void ReqUpdate();
	void TEST();
};
