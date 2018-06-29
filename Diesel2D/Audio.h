#pragma once
#include<string>
#include<SDL_mixer.h>
#include <SDL.h>
#include <windows.h>

using namespace std;
class Audio
{
private:
	string ExePath();
public:
	Audio(string musicfile, string effectfile);
	void Play(int loop);
	void ChangeEffectVolume(int volume);
	void ChangeMusicolume(int volume);
	void PlayEffect(int loop);
	void Pause();
	void Resume();
	void ChangeMusic(string file);
	void ChangeEffect(string file);
	Mix_Music *music;
	Mix_Chunk *effect;
	~Audio();
};
