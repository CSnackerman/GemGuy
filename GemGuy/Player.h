#pragma once

#include <SDL_rect.h>
#include <SDL_render.h>

#include "Config.h"
#include "Vec2.h"

enum class Direction {
	UP, DOWN, LEFT, RIGHT, NONE
};

class Player
{
public:
	
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;

	SDL_Rect rect;
	SDL_Color color;

	Player();

	void draw (SDL_Renderer* renderer);

	void move (Direction d);

	void update (float dt);

private:
	void bindRect();
	void setColor(int r, int g, int b);
};

