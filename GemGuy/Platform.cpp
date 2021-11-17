#include "Platform.h"

Platform::Platform(float x, float y, float w, float h) {
	
	position.x = x;
	position.y = y;

	rect.x = position.x;
	rect.y = position.y;
	rect.w = w;
	rect.h = h;

	leftHitbox = {rect.x, rect.y + 1, 5, rect.h - 1};

	sideColor = {100, 100, 100, 255};

	setColor(233, 245, 66);
}

void Platform::draw(SDL_Renderer* renderer) {
	
	SDL_SetRenderDrawColor (renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect (renderer, &this->rect);

	SDL_SetRenderDrawColor (renderer, sideColor.r, sideColor.g, sideColor.b, sideColor.a);
	SDL_RenderFillRect (renderer, &leftHitbox);
}

void Platform::setColor(int r, int g, int b) {
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 255;
}
