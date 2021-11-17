#pragma once

#include <vector>

#include "Platform.h"
#include "Goal.h"

class Levels {

public:
    static int current;
    std::vector <Platform> platforms;
    Goal goal;

    Levels();

    void loadLevel (int level);

    void display (SDL_Renderer* renderer);
};