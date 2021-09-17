#pragma once

#include <iostream>

#include <SDL_keyboard.h>

#include "Player.h"

class Keyboard
{
public:
	static void listen(bool& run, Player& p);
};

