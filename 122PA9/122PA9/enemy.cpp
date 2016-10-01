#pragma once
#include "enemy.h"
#include "random.h"
enemy::enemy()
{
	rect.setSize(Vector2f(32, 32));
	rect.setFillColor(Color::Red);
	rect.setPosition(200, 200);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
}

void enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

void enemy::updatemovement()
{

	if (direction == 1) {

		rect.move(0, -movementspeed);
		sprite.setTextureRect(IntRect(32 * walkcounter, 32*2, 32, 32));
		walkcounter++;


	}
	else if (direction == 2) {

		rect.move(0, movementspeed);
		sprite.setTextureRect(IntRect(32 * walkcounter, 32*3, 32, 32));
		walkcounter++;



	}
	else if (direction == 3) { //Left

		rect.move(-movementspeed, 0);
		sprite.setTextureRect(IntRect(32*walkcounter, 32, 32, 32));
		walkcounter++;


	}
	else if (direction == 4) { //Right

		rect.move(movementspeed, 0);
		sprite.setTextureRect(IntRect(32 * walkcounter, 0, 32, 32));
		walkcounter++;



	}
	else {
		//no movement
	}



	if (walkcounter == 4) {
		walkcounter = 0;
	}


	counter++;
	if (counter >= 150) {
		direction = generateRandom(10);
		counter = 0;
	}

}