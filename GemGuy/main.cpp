#include <iostream>
#include <cstdlib>
#include <string>

#include <SDL2/SDL.h>

#include "Config.h"
#include "Events.h"
#include "Keyboard.h"
#include "Player.h"
#include "Platform.h"
#include "Time.h"
#include "Levels.h"

#undef main

int main() {

	// SETUP
	SDL_Init (SDL_INIT_EVERYTHING);

	SDL_Window* window;
	SDL_Renderer* renderer;
	
	SDL_CreateWindowAndRenderer (
		Config::WIDTH, 
		Config::HEIGHT, 
		0, 
		&window, 
		&renderer
	);

	// Game Objects
	Time time;
	Levels level;
	Player player;

	level.loadLevel (1);

	// GAME LOOP
	bool run = true;
	while (run) {
		
		// timing
		SDL_Delay (3);
		time.calc_dt ();
		time.calc_fps ();
		time.show_fps (window);
		
		// keyboard & events
		Events::listen (run);
		Keyboard::listen (run, player);

		// update
		player.collide (level.platforms);
		player.update (time.dt);

		// clear screen
		SDL_SetRenderDrawColor (renderer, 0x32, 0xA8, 0x52, 0xFF);
		SDL_RenderClear (renderer);

		// draw
		player.draw (renderer);

		level.display(renderer);

		// swap frame buffer
		SDL_RenderPresent (renderer);
	}

	// quit
	SDL_DestroyWindow (window);
	SDL_Quit();
	

	return 0;
}