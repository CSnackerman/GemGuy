#pragma once

#include <iostream>

#include <SDL_rect.h>
#include <SDL_render.h>

#include "Config.h"
#include "Vec2.h"
#include "Platform.h"

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
	
	bool onGround = false;
	bool bonkHead = false;

	Player();

	void draw (SDL_Renderer* renderer);

	void move (Direction d);

	void update (float dt);

	SDL_bool collide (Platform p [], int numPlats);

private:
	void bindRect();
	void setColor(int r, int g, int b);
	bool isAbove(Platform &p);
};

