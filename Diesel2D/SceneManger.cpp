#include "SceneManger.h"
#include <vector>
#include <unordered_map>
#include "GameObject.h"
#include "SceneManger.h"
#include "Engine.h"
using namespace std;

std::unordered_map<int, struct Scene> SceneManger::Scenes;
struct Scene SceneManger::Curret;

SceneManger::SceneManger()
{
}


void SceneManger::LoadScene(struct Scene Scene_Old, struct Scene Scene_Load)
{
	Engine eng = Engine();
	for (GameObject go : Scene_Old.GameObjects)
	{
		SDL_DestroyTexture(go.Texture);
		SDL_FillRect(go.Surface, NULL, 0x000000);
	}
	Scene_Old.GameObjects.clear();
	SDL_RenderClear(eng.ren.renderer);
	Curret = Scene_Load;

}



SceneManger::~SceneManger()
{
}
