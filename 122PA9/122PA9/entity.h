#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class entity {

public:

	//Physical Object
	RectangleShape rect;
	Sprite sprite;
	Text text;

	bool active = false;
	bool deleteit = false;
	int x = 0;
	int y = 0;
	entity();


private:
protected:
};