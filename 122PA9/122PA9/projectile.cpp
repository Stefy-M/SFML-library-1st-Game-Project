#include "projectile.h"

projectile::projectile()
{
	rect.setSize(Vector2f(25, 25));
	rect.setFillColor(Color::Red);
	rect.setPosition(0, 0);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));

}

void projectile::update()
{
	if (direction == 1) { //up
		rect.move(0, -1);
		sprite.setTextureRect(IntRect(counter*32, 3*32, 32, 32));
	}
	if (direction == 2) {// down
		rect.move(0, 1);
		sprite.setTextureRect(IntRect(counter * 32, 0, 32, 32));
	}
	if (direction == 3) {//left
		rect.move(-1, 0);
		sprite.setTextureRect(IntRect(counter * 32, 32, 32, 32));
	}
	if (direction == 4) {// right
		rect.move(1, 0);
		sprite.setTextureRect(IntRect(counter * 32, 32*2, 32, 32));
	}
	counterLifetime++;
	if (counterLifetime >= 500) {
		destroy = true;
	}

	counter++;
	if (counter >= 2) {
		counter = 0;
	}

	//Sprite set at rect
	sprite.setPosition(rect.getPosition());
}
