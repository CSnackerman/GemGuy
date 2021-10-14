#pragma once

#include <vector>

#include "Platform.h"

class Levels {

public:
    static int current;
    std::vector <Platform> platforms;

    Levels();

    void loadLevel (int level);

    void display (SDL_Renderer* renderer);
};