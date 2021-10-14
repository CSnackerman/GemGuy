#include "Levels.h"

// intialize static variables
int Levels::current = 0;

Levels::Levels() {
}

void Levels::loadLevel (int level) {

    if (level == 1) {

        platforms.clear();
        platforms = {
            Platform (0, Config::HEIGHT - 25, Config::WIDTH, 25),
    		Platform (0, Config::HEIGHT - 150, Config::WIDTH - 100, 25)
        };
    }

}   

void Levels::display (SDL_Renderer* renderer) {
    for (auto &platform : platforms) {
        platform.draw (renderer);
    }
}