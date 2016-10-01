#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "player.h"
#include "entity.h"
#include "projectile.h"
#include "enemy.h"
#include "menu.h"
#include "random.h"
#include "textDisplay.h"
#include "EndPage.h"
#include "pickup.h"
int main() {
	EndPage end;
	Clock clock;
	Clock clock2;
	Clock clock3;
	//Variables
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;
	char option;
	


	RenderWindow window(VideoMode(800, 400), "GAME");
	window.setActive(32);
	Menu menu(window.getSize().x, window.getSize().y);

	//background
	sf::Texture backgroundtexture;
	if (!backgroundtexture.loadFromFile("tempBG.png")) {
		return EXIT_FAILURE;
	}
	Sprite background(backgroundtexture);


	//Load player1 texture
	sf::Texture player1texture;
	if (!player1texture.loadFromFile("KarateBoy.png")) {
		return EXIT_FAILURE;
	}
	player player1;
	player1.sprite.setTexture(player1texture);


	//Load player1 grunt buffer
	
	sf::SoundBuffer player1GruntBuffer;
	if (!player1GruntBuffer.loadFromFile("Male Grunt.wav")) {
		return EXIT_FAILURE;
	}
	sf::Sound player1Grunt;
	player1Grunt.setBuffer(player1GruntBuffer);


	// Load Pickup Item Noise
	sf::SoundBuffer diamondbuffer;
	if (!diamondbuffer.loadFromFile("Coin.wav")) {
		return EXIT_FAILURE;
	}
	sf::Sound diamondPickup;
	diamondPickup.setBuffer(diamondbuffer);

	//Load Enemy Texture
	sf::Texture enemytexture;
	if (!enemytexture.loadFromFile("Zombie.png")) {
		return EXIT_FAILURE;
	}
	//Load Diamond texture
	sf::Texture Diamondtexture;
	if (!Diamondtexture.loadFromFile("Diamond.png")) {
		return EXIT_FAILURE;
	}

	//Load zombie noise
	sf::SoundBuffer zombieBuffer;
	if (!zombieBuffer.loadFromFile("Zombie.wav")) {
		return EXIT_FAILURE;
	}
	sf::Sound zombieGrowl;
	zombieGrowl.setBuffer(zombieBuffer);

	//Load Hadoken 
	sf::SoundBuffer hadokenBuffer;
	if (!hadokenBuffer.loadFromFile("Hadoken.wav")) {
		return EXIT_FAILURE;
	}
	sf::Sound hadokenScream;
	hadokenScream.setBuffer(hadokenBuffer);



	//Enemy Vector Array
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;

	// Set enemy texture
	enemy enemy1;
	enemy1.sprite.setTexture(enemytexture);

	enemy1.rect.setPosition(400, 200);
	enemyArray.push_back(enemy1);


	
	Texture fireballTexture;
	if (!fireballTexture.loadFromFile("Fireball.png")) {
		return EXIT_FAILURE;
	}
	//Projectile Vector Array
	vector<projectile>::const_iterator iter;
	vector<projectile> projectileArray;
	
	

	//Projectile Object
	class projectile projectile1;
	projectile1.sprite.setTexture(fireballTexture);



	//Text Vector Array
	vector<textDisplay>::const_iterator iter8;
	vector<textDisplay> textDisplayArray;

	//Pickup vector Array
	vector<pickup>::const_iterator iter11;
	vector<pickup> pickupArray;
	
	//Diamond object
	class pickup pickup1;
	pickup1.sprite.setTexture(Diamondtexture);
	pickup1.rect.setPosition(400, 200);
	pickupArray.push_back(pickup1);

	pickup1.rect.setPosition(100, 300);
	pickupArray.push_back(pickup1);



	//Create text to display
	sf::Font font;
	if (!font.loadFromFile("sansation.ttf")) {
		return EXIT_FAILURE;
	}

	//Text Display Object
	class textDisplay textDisplay1;
	textDisplay1.text.setFont(font);
	//textDisplayArray.push_back(textDisplay1);


	//HUD dipslay font
	sf::Font HUD;
	if (!HUD.loadFromFile("slkscr.ttf")) {
		return EXIT_FAILURE;
	}

	//Press y command
	sf::Text press("TAP Y FOR SOME FUN >:)...\nKILL ZOMBIES TO EARN DIAMONDS!!!",HUD,40);
	press.setColor(Color::Red);
	press.setPosition(50, 200);
	

	//Wallet display
	sf::Text wallet("Wallet: ", HUD, 25);
	wallet.setColor(Color::Black);
	wallet.setCharacterSize(25);
	wallet.setPosition(500, 0);








	// Load Backgroundmusic
	sf::Music backgroundmusic;
	if (!backgroundmusic.openFromFile("retro.wav")) {
		return EXIT_FAILURE;
	}







	
	

	//cin >> option;
	//cout << option;
	
	while (window.isOpen()) 
	{

		Event event;

		while (window.pollEvent(event)) 
		{
			if (player1.alive == false) 
			{
				window.close();
				cout << "GAME OVER!!!\n\n" << endl;
				cout << "PLAYER LOOT: " << player1.wallet <<"k"<< endl;
				cout << "YOU EXTERMINTED " << player1.killedZomibies << " ZOMBIES" << endl;
				system("pause");
				

			}

			if (event.type == Event::Closed) // When user closes window
			{ 
				window.close();
			}
			
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code) 
				{
				case sf::Keyboard::Y:
					//cout << "y pressed" << endl;
					backgroundmusic.setVolume(50);
					backgroundmusic.play();
					press.setPosition(10000, 10000); // Coulndt find a way to erase text so i send off screen
					break;
				
				}

				break;
			
			}
			





			//update player
			player1.update();
			player1.updatemovement();
			
		}
		
		window.clear();

		//Clock
		Time elapsed1 = clock.getElapsedTime();
		Time elapsed2 = clock2.getElapsedTime();
		Time elapsed3 = clock3.getElapsedTime();

		




		//Player collides with Diamond
		counter = 0;
		for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++) {
			if (player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds())) 
			{
				if (pickupArray[counter].isDiamond ==true) {
					player1.wallet += 5;
					diamondPickup.play();

				}
				pickupArray[counter].destroy = true;
			}

			counter++;
		}







		
		if (elapsed2.asSeconds() >= .5)
		{
			clock2.restart();
			//Enemy Collides with Player (Player takes damage)
			counter = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
				if (player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds())) {
					// Text Display
					textDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
					textDisplay1.text.setPosition(player1.rect.getPosition().x,
						player1.rect.getPosition().y);
					textDisplayArray.push_back(textDisplay1);


					//Player loses hp and grunts
					player1.hp -= enemyArray[counter].attackDamage;
					player1Grunt.play();

					if (player1.hp <= 0) {
						player1.alive = false;
					}
				}
				
				
				counter++;
			}
		}
		//cout << player1.hp << endl;

		












		// Projectile collides with enemy
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {

			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
				if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					//cout << "collisison" << endl;
					projectileArray[counter].destroy = true;


					// Text Display
					textDisplay1.text.setString(to_string(1));
					textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x,
						enemyArray[counter2].rect.getPosition().y);
					textDisplayArray.push_back(textDisplay1);


					enemyArray[counter2].hp--; //-=projectileArray[counter].attackDamage;
					if (enemyArray[counter2].hp <= 0)
					{
						enemyArray[counter2].alive = false;
						player1.killedZomibies++;
						
						
					}
				}


				counter2++;
			}

			counter++;
		}


		// Delete dead enemy
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
			if (enemyArray[counter].alive == false)
			{
				zombieGrowl.play();
				//cout << "enemy dead" << endl;
				if (generateRandom(3) == 1) 
				{
					pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
					pickupArray.push_back(pickup1);


				}
				
				enemyArray.erase(iter4);

				break;
			}


			counter++;
		}


		//Destroy projectile
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
			if (projectileArray[counter].destroy == true)
			{
				//cout << "enemy dead" << endl;
				projectileArray.erase(iter);
				break;
			}

			counter++;
		}

		//Delete text display
		counter = 0;
		for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
		{
			if (textDisplayArray[counter].destroy == true)
			{
				textDisplayArray.erase(iter8);
				break;
			}
			counter++;

		}


		//Delete Pickup Item
		counter = 0;
		for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++) {
			if (pickupArray[counter].destroy == true) {
				pickupArray.erase(iter11);
				break;
			}
			counter++;
		}







		//Spawns enemies
		if (Keyboard::isKeyPressed(Keyboard::Y))
		{
			enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
			enemyArray.push_back(enemy1);
			/*enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
			enemyArray.push_back(enemy1);*/
		}










		
		window.draw(background);
	
		
		//Fires Missle(Space)
		
		if (elapsed1.asSeconds() >= 0.2)
		{
			clock.restart();
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				hadokenScream.play();
				projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x / 2 - projectile1.rect.getSize().x / 2, player1.rect.getPosition().y
					+ player1.rect.getSize().y / 2 - projectile1.rect.getSize().y / 2);
				projectile1.direction = player1.direction;
				projectileArray.push_back(projectile1);

			}
		}
		

		//Draw Projectiles
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
			projectileArray[counter].update(); // Update projectile
			//window.draw(projectileArray[counter].rect);
			window.draw(projectileArray[counter].sprite);
			counter++;
		}

		//Draw Pickup Item
		counter = 0;
		for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++) {
			pickupArray[counter].update(); // Update pickupitem
			window.draw(pickupArray[counter].sprite);
			counter++;
		}
		



		//Draw Enemies
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
			enemyArray[counter].update(); // Update enemies
			enemyArray[counter].updatemovement();
			//window.draw(enemyArray[counter].rect);
			window.draw(enemyArray[counter].sprite);
			counter++;
		}
		




		//DRAW EVERYTHING TO WINDOW HERE
		window.draw(player1.sprite);


		//Draw text
		counter = 0;
		for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
		{
			textDisplayArray[counter].update();
			window.draw(textDisplayArray[counter].text);
			counter++;
		

		}
		/*
		if (player1.alive == false) {
			end.draw(window);
		}*/

		// HUD
		wallet.setString("Wallet : " + to_string(player1.wallet) +"k"+"\n"+ "HP: "+ to_string(player1.hp)+
			"\n"+"Dead Zombies: "+to_string(player1.killedZomibies));
		window.draw(press);
		
		
		window.draw(wallet);

		

		//     ^^^^^


		window.display();
		/*if (!window.isOpen()) {
			cout << "GAME OVER!!!\n\n" << endl;
			cout << "PLAYER LOOT: " << player1.wallet << endl;
			cout << "YOU EXTERMINTED " << player1.killedZomibies << " ZOMBIES" << endl;
		}*/
		


	}
	

}