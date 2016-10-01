#ifndef PROJECTILE_H
#define PROJECTILE_H



#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "entity.h"

using namespace sf;
using namespace std;

class projectile : public entity {

public:
	//projectile attributes
	float movementspeed = 2;
	int attackDamage = 1;
	int direction = 0; // 1 - up, 2- down, 3 -left, 4 - right
	bool destroy = false;
	int counterLifetime = 0;
	int lifeTime = 200; //Projectile Lifetime before destroyed
	int counter = 0;



					   //Player functions
	projectile();


	void update();
	//void updateMovement();
private:

};


#endif