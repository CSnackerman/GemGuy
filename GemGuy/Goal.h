#pragma once

#include <SDL_rect.h>

#include "Vec2.h"

#include <SDL_render.h>


class Goal {
public:

    Vec2 position;
    SDL_Rect rect;
    SDL_Color color;

    Goal ();
    Goal(int x, int y);

    void draw (SDL_Renderer* renderer);
};