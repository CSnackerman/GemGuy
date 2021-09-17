#pragma once

#include <string>

#include <SDL_timer.h>
#include <SDL_video.h>

class Time
{
public:
	Uint32 start;
	Uint32 stop;
	float dt;
	float t;
	Uint32 framecount;
	int fps;
	static constexpr float fps_calc_frequency = 0.5f; // sec

	
	Time();

	void calc_dt();
	void calc_fps();

	void show_fps(SDL_Window* window);
};

