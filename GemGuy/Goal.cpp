# include "Goal.h"

Goal::Goal() {
    position.x = 0;
    position.y = 0;

    rect.x = position.x;
    rect.y = position.y;
    rect.w = 25;
    rect.h = 25;

    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
}


Goal::Goal (int x, int y) {
    position.x = x;
    position.y = y;

    rect.x = position.x;
    rect.y = position.y;
    rect.w = 25;
    rect.h = 25;

    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
}


void Goal::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor (renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect (renderer, &this->rect);
}