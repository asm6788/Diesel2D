#pragma once

#include <vector>
#include <unordered_map>
#include "GameObject.h"
#include "UI.h"

class SceneManger
{
public:
	static std::unordered_map<int, struct Scene> Scenes;
	static Scene Curret;
	void LoadScene(struct Scene Scene_Old, struct Scene Scene_Load);
	~SceneManger();
	SceneManger();
};

struct Scene
{
public:
	int ID;
	std::string Name;
	std::vector<GameObject *> GameObjects;
	std::vector<UI *> UIs;
	Scene(int ID, std::string Name)
	{
		this->ID = ID;
		this->Name = Name;
	}
	Scene()
	{
	}
};
