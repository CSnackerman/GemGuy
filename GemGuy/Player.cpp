#include "Player.h"

Player::Player() {
	
	int w = Config::WIDTH / 15;
	int h = w;
	float x = static_cast<float> (Config::WIDTH / 2 - w / 2);
	float y = static_cast<float> (Config::HEIGHT / 2 - h / 2);

	position.x = x;
	position.y = y;

	velocity = Vec2();
	acceleration = Vec2();

	rect.w = w;
	rect.h = h;

	bindRect();

	setColor (0, 91, 156);

}

void Player::move(Direction d) {

	printf("%.5f    %.5f\n", velocity.x, velocity.y);

	switch (d) {
		
		case Direction::UP:
			if (onGround) {
				position.y -= 1.0f;
				velocity.y = -Config::JUMP_POWER;
			}
			break;

		case Direction::DOWN:
			break;

		case Direction::LEFT:
			acceleration.x = -Config::ACCEL;
			break;

		case Direction::RIGHT:
			acceleration.x = Config::ACCEL;
			break;

		case Direction::NONE:
			
			// decelerate
			if (velocity.x > 0.1f) {
				acceleration.x = -Config::ACCEL;
			}
			else if (velocity.x < -0.1f) {
				acceleration.x = Config::ACCEL;
			}
			else {
				acceleration.x = 0.0f;
				velocity.x = 0.0f;
			}
			
			break;
	}

}

void Player::update(float dt) {

	// add gravity
	acceleration.y = Config::GRAVITY;
	if (onGround) {
		acceleration.y = 0;
		velocity.y = 0;
	}

	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
	
	// impose speed limit
	if (velocity.x > Config::SPEED) {
		velocity.x = Config::SPEED;
	}
	else if (velocity.x < -Config::SPEED) {
		velocity.x = -Config::SPEED;
	}

	position.x += velocity.x * dt;
	position.y += velocity.y * dt;

	bindRect();
}

void Player::draw(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor (renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect (renderer, &this->rect);
}

SDL_bool Player::collide(Platform& p) {

	SDL_bool touchingPlat = SDL_HasIntersection (&this->rect, &p.rect);

	if (touchingPlat) {
		onGround = true;
		return touchingPlat;
	}

	onGround = false;
	return SDL_FALSE;
}

void Player::bindRect() {

	rect.x = static_cast<int> (position.x);
	rect.y = static_cast<int> (position.y);
}

void Player::setColor(int r, int g, int b) {
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 255;
}