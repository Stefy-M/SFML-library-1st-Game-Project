#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class EndPage {
public:

	EndPage();

	void draw(sf::RenderWindow &window);

private:
	sf::SoundBuffer buffer;
	sf::Sound endSound;
	sf::Text text;
	sf::Font font;
	string End = "GAME OVER";
	sf::Texture backgroundtexture;
	sf::Sprite background;
};