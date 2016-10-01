#include "player.h"

player::player()
{
	rect.setSize(Vector2f(32, 32));
	rect.setFillColor(Color::Red);
	rect.setPosition(200, 200);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
}

void player::update()
{
	sprite.setPosition(rect.getPosition());
}

void player::updatemovement()
{
	 if (Keyboard::isKeyPressed(Keyboard::Left)) {
		direction = 3;
		rect.move(-2, 0);
		sprite.setTextureRect(IntRect(walkcounter * 32, 32, 32, 32));
		walkcounter++;

	}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
		direction = 4;
		rect.move(2, 0);
		sprite.setTextureRect(IntRect(walkcounter * 32, 0, 32, 32));
		walkcounter++;

	}
	  else if (Keyboard::isKeyPressed(Keyboard::Up)) {
		direction = 1;
		rect.move(0, -2);
		sprite.setTextureRect(IntRect(walkcounter * 32, 32*3, 32, 32));
		walkcounter++;

	}
	  else if (Keyboard::isKeyPressed(Keyboard::Down)) {
		direction = 2;
		rect.move(0, 2);
		sprite.setTextureRect(IntRect(walkcounter * 32, 32*2, 32, 32));
		walkcounter++;

	}
	  else if (Keyboard::isKeyPressed(Keyboard::Space)) {
		//direction = 2;
		//rect.move(0, movementspeed);
		sprite.setTextureRect(IntRect(walkcounter * 32, 32 * 4, 32, 32));
		walkcounter++;

	}


	if (walkcounter == 4) {
		walkcounter = 0;
	}
}
