#include <iostream>
#include <cstdlib>
#include <string>

#include <SDL.h>

#include "Config.h"
#include "Events.h"
#include "Keyboard.h"
#include "Player.h"
#include "Platform.h"
#include "Time.h"

// IDK Why but must have
#undef main

int main() {

	// SETUP
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window;
	SDL_Renderer* renderer;
	

	SDL_CreateWindowAndRenderer (
		Config::WIDTH, 
		Config::HEIGHT, 
		0, 
		&window, 
		&renderer
	);

	Time time;

	Player player;

	Platform platforms [2] = { 
		Platform (0, Config::HEIGHT - 25, Config::WIDTH, 25),
		Platform (0, Config::HEIGHT - 150, Config::WIDTH, 25)
	};

	int numPlatforms = sizeof (platforms) / sizeof (platforms [0]);


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
		player.collide (platforms, numPlatforms);
		player.update (time.dt);

		// clear screen
		SDL_SetRenderDrawColor (renderer, 0x32, 0xA8, 0x52, 0xFF);
		SDL_RenderClear (renderer);

		// draw
		player.draw (renderer);

		for (auto& p : platforms) {
			p.draw (renderer);
		}

		// swap frame buffer
		SDL_RenderPresent (renderer);
	}

	// quit
	SDL_DestroyWindow (window);
	SDL_Quit();
	

	return 0;
}