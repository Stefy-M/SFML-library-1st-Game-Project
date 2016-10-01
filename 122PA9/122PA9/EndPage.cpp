#include "EndPage.h"


EndPage::EndPage()
{
	
	font.loadFromFile("sansation.ttf");
	backgroundtexture.loadFromFile("GameOver.jpg");
	background.setTexture(backgroundtexture);
	background.setPosition(400, 200);
	
	buffer.loadFromFile("GameOver.wav");
	endSound.setBuffer(buffer);

	

	text.setPosition(400, 200);
	text.setColor(Color::White);
	text.setCharacterSize(50);
	text.setString(End);




}

void EndPage::draw(sf::RenderWindow & window)
{
	endSound.play();
	window.clear();
	window.draw(background);
	//window.display();
	

	
	
	
}
