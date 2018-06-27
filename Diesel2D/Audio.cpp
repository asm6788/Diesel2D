#include "Audio.h"
#include <SDL.h>
#include<SDL_mixer.h>
#include<string>
#include <windows.h>

Audio::Audio(string musicfile, string effectfile)
{
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	if (musicfile != "")
		music = Mix_LoadMUS(ExePath().append("\\").append(musicfile).c_str());
	if (effectfile != "")
		effect = Mix_LoadWAV(ExePath().append("\\").append(effectfile).c_str());
}

void Audio::Play(int loop)
{
	Mix_PlayMusic(music, loop);
}

void Audio::ChangeEffectVolume(int volume)
{
	Mix_VolumeChunk(effect, volume);
}

void Audio::ChangeMusicolume(int volume)
{
	Mix_Volume(1, volume);
}

void Audio::PlayEffect(int loop)
{
	Mix_PlayChannel(1, effect, loop);
}

void Audio::Pause()
{
	Mix_PauseMusic();
}

void Audio::Resume()
{
	Mix_ResumeMusic();
}

void Audio::ChangeMusic(string file)
{
	music = Mix_LoadMUS(ExePath().append(file).c_str());
}

void Audio::ChangeEffect(string file)
{
	effect = Mix_LoadWAV(ExePath().append("\\").append(file).c_str());
}

string Audio::ExePath()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

Audio::~Audio()
{
}