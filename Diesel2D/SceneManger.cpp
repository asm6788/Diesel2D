#include "SceneManger.h"
#include <vector>
#include <unordered_map>
#include "GameObject.h"
#include "SceneManger.h"
using namespace std;

std::unordered_map<int, struct Scene> SceneManger::Scenes;
struct Scene SceneManger::Curret;

SceneManger::SceneManger()
{
}


void SceneManger::LoadScene(struct Scene Scene_Old, struct Scene Scene_Load)
{
	for (int i = 0; i != Scene_Old.GameObjects.size(); i++)
	{
		SDL_DestroyTexture(Scene_Old.GameObjects[i].Texture);
	}
	Scene_Old.GameObjects.clear();
	Curret = Scene_Load;

}



SceneManger::~SceneManger()
{
}
