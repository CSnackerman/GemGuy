#include <iostream>

#include <SDL.h>

#undef main


void handleEvents(SDL_Event& event, bool& run) {
	
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			run = false;
		}
	}

	return;
}

void handleKeyboard(bool& run) {
	// keyboard state
	const Uint8* keystate = SDL_GetKeyboardState(nullptr);

	// ALT-F4
	if (keystate[SDL_SCANCODE_LALT] && keystate[SDL_SCANCODE_F4]) {
		run = false;
	}

	// UP
	if (keystate[SDL_SCANCODE_UP]) {
		std::cout << "Pressing UP" << std::endl;
	}
	
	// DOWN
	if (keystate[SDL_SCANCODE_DOWN]) {
		std::cout << "Pressing DOWN" << std::endl;
	}

	// LEFT
	if (keystate[SDL_SCANCODE_LEFT]) {
		std::cout << "Pressing LEFT" << std::endl;
	}

	// RIGHT
	if (keystate[SDL_SCANCODE_RIGHT]) {
		std::cout << "Pressing RIGHT" << std::endl;
	}
}


int main() {

	// SETUP
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	SDL_CreateWindowAndRenderer (800, 600, 0, &window, &renderer);


	// GAME LOOP
	bool run = true;
	while (run) {
		
		handleEvents (event, run);
		handleKeyboard (run);

		SDL_SetRenderDrawColor (renderer, 0x32, 0xA8, 0x52, 0xFF);
		SDL_RenderClear (renderer);
		SDL_RenderPresent (renderer);
	}

	// quit
	SDL_DestroyWindow (window);
	SDL_Quit();
	

	return 0;
}