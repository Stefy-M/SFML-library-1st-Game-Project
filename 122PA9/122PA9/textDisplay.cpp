#pragma once
#include "textDisplay.h"

textDisplay::textDisplay()
{
	
	text.setColor(sf::Color::Red);
	text.setCharacterSize(15);
	text.setPosition(300, 300);
	text.setString(myString);
}

void textDisplay::update()
{
	text.move(0, -.5);
	counter++;
	if (counter >= lifetime) {
		destroy = true;
	}
}

