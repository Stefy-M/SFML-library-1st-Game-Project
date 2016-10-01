#pragma once
#include "pickup.h"



pickup::pickup()
{
	rect.setSize(Vector2f(32, 32));
	rect.setFillColor(Color::Yellow);
	rect.setPosition(0, 0);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
}

void pickup::update()
{
	sprite.setPosition(rect.getPosition());
}

