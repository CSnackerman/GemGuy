#pragma once

#include <SDL_rect.h>
#include <SDL_render.h>

#include "Config.h"
#include "Vec2.h"

class Platform
{
public:
	Vec2 position;

	SDL_Rect rect;
	SDL_Color color;

	Platform () = delete;
	Platform (float x, float y, float w, float h);

	void draw (SDL_Renderer* renderer);

private:
	void setColor(int r, int g, int b);
};

