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
	static constexpr float ACCEL = 10.0f;
	static constexpr float SPEED = 100.0f;
};
