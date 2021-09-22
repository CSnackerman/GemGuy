#pragma once
class Config
{
public:
	
	// window
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;

	// time
	static constexpr int DELAY = 3;

	// world
	static constexpr float GRAVITY = 9.8f;

	// player
	static constexpr float ACCEL = 50.0f;
	static constexpr float SPEED = 1000.0f;
	static constexpr float JUMP_POWER = 1000.0f;
};
