#include "Keyboard.h"

void Keyboard::listen(bool& run, Player& p) {

	// keyboard state
	const Uint8* keystate = SDL_GetKeyboardState(nullptr);

	// ALT-F4
	if (keystate[SDL_SCANCODE_LALT] && keystate[SDL_SCANCODE_F4]) {
		run = false;
	}

	// keys
	Uint8 up = keystate [SDL_SCANCODE_UP];
	Uint8 down = keystate [SDL_SCANCODE_DOWN];
	Uint8 left = keystate [SDL_SCANCODE_LEFT];
	Uint8 right = keystate [SDL_SCANCODE_RIGHT];


	if (up) {
		std::cout << "Pressing UP" << std::endl;
	}

	if (down) {
		std::cout << "Pressing DOWN" << std::endl;
	}

	if (left) {
		std::cout << "Pressing LEFT" << std::endl;
		p.move (Direction::LEFT);
	}

	if (right) {
		std::cout << "Pressing RIGHT" << std::endl;
		p.move (Direction::RIGHT);
	}

	// no horizontal keys pressed
	if (!left && !right) {
		p.move (Direction::NONE);
	}
}