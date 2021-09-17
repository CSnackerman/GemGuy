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

	switch (d) {
		
		case Direction::UP:
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
			acceleration.x = 0;
			velocity.x = 0;
			break;
	}

}

void Player::update(float dt) {


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