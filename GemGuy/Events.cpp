#include "Events.h"

void Events::listen (bool& run) {
	
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			run = false;
		}
	}

	return;
}
