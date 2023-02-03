#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "config.h"
#include "tank.h"
#include "bullet.h"
#include "map.h"
#include "game.h"
#include "enemys.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(810, 540), "Tanks");	// 810 = 27*30, 540 = 27*20

	window.display();

	bool first_start_game = true;

	start:
	game game_one(-2);
	if (!first_start_game) game_one.setStatus(-1);

	first_start_game = false;

	// Drawing main menu (status = -1, -2)
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		window.clear();

		int game_status_solve = game_one.status(100, 100);

		game_one.draw(window);

		if (game_status_solve == 1) break;

		window.display();
	}

	map map_one(0);
	enemys enemys_one;
	enemys_one.initialize(game_one);

	//Drawing game (status = 1) and end game (status = 2 or 3)
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		window.clear();

		int game_status_solve = game_one.status(enemys_one.getTanks()[0]->getHealth(), enemys_one.getTanks()[1]->getHealth());
		switch (game_status_solve)
		{
			case 1:
				map_one.draw(window);
				enemys_one.draw(game_status_solve, window);
				game_one.draw(window);
				map_one.drawEffect(window);

				map_one.DieEffect();
				enemys_one.access_path(map_one);
				enemys_one.move_control();
				enemys_one.fire_control();
				enemys_one.bullet_collision(map_one, game_one);
				enemys_one.bonus_control(map_one);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))	goto start;
				break;

			case 2:
				map_one.draw(window);
				enemys_one.draw(game_status_solve, window);
				game_one.draw(window);
				map_one.drawEffect(window);

				map_one.DieEffect();
				for (size_t i = 1; i < TANKS_COUNTER; i++)
				{
					enemys_one.getTanks()[i]->Die();
					for (size_t j = 0; j < enemys_one.getTanks()[i]->getBulletsCounter(); j++)	enemys_one.getTanks()[i]->getBullets()[j]->Die();
				}
				map_one.base_Die(1);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))	goto start;
				break;

			case 3:
				map_one.draw(window);
				enemys_one.draw(game_status_solve, window);
				game_one.draw(window);
				map_one.drawEffect(window);

				map_one.DieEffect();
				enemys_one.getTanks()[0]->Die();
				for (size_t i = 2; i < TANKS_COUNTER; i++)
				{
					enemys_one.getTanks()[i]->Die();
					for (size_t j = 0; j < enemys_one.getTanks()[i]->getBulletsCounter(); j++)	enemys_one.getTanks()[i]->getBullets()[j]->Die();
				}
				map_one.base_Die(0);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))	goto start;
				break;
		}

		game_one.text_win(game_status_solve, window);


		window.display();
	}

	return 0;
}
