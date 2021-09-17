#include "Time.h"

Time::Time() {
	start = SDL_GetTicks();
	stop = 0;
	dt = 0.0f;
	t = 0.0f;
	framecount = 0;
	fps = 0;

}


void Time::calc_dt() {

	stop = SDL_GetTicks();
	dt = (stop - start) / 1000.0f;
	start = SDL_GetTicks();

	framecount++;
	t += dt;
}

void Time::calc_fps() {
	
	if (t > fps_calc_frequency) {
		
		fps = static_cast <int> (framecount / t);
		
		// reset counters
		t = 0.0f;
		framecount = 0.0f;
	}
}

void Time::show_fps(SDL_Window* window) {

	std::string fps_string = std::to_string (fps) + " fps";
	SDL_SetWindowTitle( window, fps_string.c_str() );
}