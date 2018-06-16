#pragma once
#include<string>
#include"Render.h"
#include <functional>
#include "EventSystem\event_system.h"

using namespace std;
class Engine
{
public:
	Render ren;
	Event Update{};
	~Engine();
	Engine(int SceneID, string Scene, string title, int posX, int posY, int width, int height);
	void ReqUpdate();
	void TEST();
};

