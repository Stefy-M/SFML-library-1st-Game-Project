#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "entity.h"

class player : public entity {

public:
	// player attributes
	int movementspeed = 2;
	int hp = 10;
	int wallet = 0;
	int killedZomibies = 0;


	// animation counters
	int walkcounter = 0;
	int attackcounter = 0;
	int direction = 0; // 1 - up, 2- down, 3 -left, 4 - right
	bool alive = true;



	// public functions
	player();
	void update();
	void updatemovement();



private:

};