#ifndef ENEMY_H
#define ENEMY_H





#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "entity.h"

class enemy : public entity {

public:
	// player attributes
	float movementspeed = 0.1;
	int attackDamage = 1;



	// animation counters
	int counter = 0;
	int walkcounter = 0;
	int attackcounter = 0;
	int direction = 0; // 1 - up, 2- down, 3 -left, 4 - right
	int hp = 3;
	bool alive = true;
	



					   // public functions
	enemy();
	void update();
	void updatemovement();



private:

};

#endif
