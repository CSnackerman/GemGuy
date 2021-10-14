#pragma once

#include <iostream>

#include <SDL.h>

#include "Player.h"

class Keyboard
{
public:
	static void listen(bool& run, Player& p);
};

