#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

#include "config.h"
#include "enemys.h"


void enemys::config()
{
	hp_bonus.loadFromFile(SOUND_HP_BONUS);
	hp_bonus_audio.setBuffer(hp_bonus);
	hp_bonus_audio.setVolume(float(100));

	texture_buff.loadFromFile(MAP_CELL_TEXTURE_BR);
	sprite_buff.setTexture(texture_buff);
}

enemys::enemys() :
	counter_(0)
{
	config();
}

enemys::tank_ptr enemys::operator [](size_t rhs) const
{
	if (rhs >= counter_)
	{
		throw std::out_of_range("Index is out of range");
	}

	return tank_array_[rhs];
}

void enemys::initialize(game &game_o)
{
	for (size_t i = 0; i < TANKS_COUNTER; i++)
	{
		int type_buff = 3;
		if (i < 2)	type_buff = game_o.getType(i);
		tank temp_tank(i, type_buff);
		enemys::tank_ptr part = std::make_shared<tank>(temp_tank);
		tank_array temp_array(std::make_unique<tank_ptr[]>(counter_ + 1));
		for (size_t i = 0; i < counter_; i++)
		{
			temp_array[i] = tank_array_[i];
		}
		temp_array[counter_] = part;
		counter_++;
		tank_array_.swap(temp_array);
	}
}

void enemys::access_path(map &map_o)
{
	for (size_t i = 0; i < counter_; i++)
	{
		for (size_t j = 0; j < counter_; j++)
		{
			if (j != i)
			{
				short int a = 0;
				short int b = 0;

				sf::FloatRect flrect;
				sf::Sprite sprite_buff_t = tank_array_[i]->getSprite();
				sf::Sprite sprite_buff_t2 = tank_array_[j]->getSprite();
				if (sprite_buff_t.getGlobalBounds().intersects(sprite_buff_t2.getGlobalBounds(), flrect))
				{
					if (tank_array_[i]->getPlayer() == 0)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (tank_array_[i]->getSpeedBoost() != 0))
						{
							if ((tank_array_[i]->getAngle() == 0) && (tank_array_[j]->getObj().pos.y < tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 1) && (tank_array_[j]->getObj().pos.x > tank_array_[i]->getObj().pos.x))	b = 1;
							if ((tank_array_[i]->getAngle() == 2) && (tank_array_[j]->getObj().pos.y > tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 3) && (tank_array_[j]->getObj().pos.x < tank_array_[i]->getObj().pos.x))	b = 1;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (tank_array_[i]->getSpeedBoost() != 0))
						{
							if ((tank_array_[i]->getAngle() == 0) && (tank_array_[j]->getObj().pos.y > tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 1) && (tank_array_[j]->getObj().pos.x < tank_array_[i]->getObj().pos.x))	b = 1;
							if ((tank_array_[i]->getAngle() == 2) && (tank_array_[j]->getObj().pos.y < tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 3) && (tank_array_[j]->getObj().pos.x > tank_array_[i]->getObj().pos.x))	b = 1;
						}
					}
					if (tank_array_[i]->getPlayer() == 1)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (tank_array_[i]->getSpeedBoost() != 0))
						{
							if ((tank_array_[i]->getAngle() == 0) && (tank_array_[j]->getObj().pos.y < tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 1) && (tank_array_[j]->getObj().pos.x > tank_array_[i]->getObj().pos.x))	b = 1;
							if ((tank_array_[i]->getAngle() == 2) && (tank_array_[j]->getObj().pos.y > tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 3) && (tank_array_[j]->getObj().pos.x < tank_array_[i]->getObj().pos.x))	b = 1;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (tank_array_[i]->getSpeedBoost() != 0))
						{
							if ((tank_array_[i]->getAngle() == 0) && (tank_array_[j]->getObj().pos.y > tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 1) && (tank_array_[j]->getObj().pos.x < tank_array_[i]->getObj().pos.x))	b = 1;
							if ((tank_array_[i]->getAngle() == 2) && (tank_array_[j]->getObj().pos.y < tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 3) && (tank_array_[j]->getObj().pos.x > tank_array_[i]->getObj().pos.x))	b = 1;
						}
					}
					if (tank_array_[i]->getPlayer() > 1)
					{
						if (tank_array_[i]->getStatusII() == 0)
						{
							if ((tank_array_[i]->getAngle() == 0) && (tank_array_[j]->getObj().pos.y < tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 1) && (tank_array_[j]->getObj().pos.x > tank_array_[i]->getObj().pos.x))	b = 1;
							if ((tank_array_[i]->getAngle() == 2) && (tank_array_[j]->getObj().pos.y > tank_array_[i]->getObj().pos.y))	b = 1;
							if ((tank_array_[i]->getAngle() == 3) && (tank_array_[j]->getObj().pos.x < tank_array_[i]->getObj().pos.x))	b = 1;
						}
					}
				}

				if (b == 0)
				{
					int xj = int((tank_array_[i]->getObj().pos.x - 13.5) / 27) - 2;
					int yi = int((tank_array_[i]->getObj().pos.y - 13.5) / 27) - 2;
					a = 1;
					for (int ii = yi; ii < (yi + 4); ii++)
					{
						for (int jj = xj; jj < (xj + 4); jj++)
						{
							if ((ii > (-1)) && (ii < 30) && (jj > (-1)) && (jj < 30))
							{
								sprite_buff.setPosition(float(map_o.getCell(ii, jj).pos.x), float(map_o.getCell(ii, jj).pos.y));
								if ((sprite_buff_t.getGlobalBounds().intersects(sprite_buff.getGlobalBounds(), flrect)) && (map_o.getCell(ii, jj).health != 0))
								{
									if (tank_array_[i]->getPlayer() == 0)
									{
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (tank_array_[i]->getSpeedBoost() != 0))
										{
											if ((tank_array_[i]->getAngle() == 0) && ((map_o.getCell(ii, jj).pos.y + 13.5) < tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 1) && ((map_o.getCell(ii, jj).pos.x + 13.5) > tank_array_[i]->getObj().pos.x))	a = 0;
											if ((tank_array_[i]->getAngle() == 2) && ((map_o.getCell(ii, jj).pos.y + 13.5) > tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 3) && ((map_o.getCell(ii, jj).pos.x + 13.5) < tank_array_[i]->getObj().pos.x))	a = 0;
										}
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (tank_array_[i]->getSpeedBoost() != 0))
										{
											if ((tank_array_[i]->getAngle() == 0) && ((map_o.getCell(ii, jj).pos.y + 13.5) > tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 1) && ((map_o.getCell(ii, jj).pos.x + 13.5) < tank_array_[i]->getObj().pos.x))	a = 0;
											if ((tank_array_[i]->getAngle() == 2) && ((map_o.getCell(ii, jj).pos.y + 13.5) < tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 3) && ((map_o.getCell(ii, jj).pos.x + 13.5) > tank_array_[i]->getObj().pos.x))	a = 0;
										}
									}
									if (tank_array_[i]->getPlayer() == 1)
									{
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (tank_array_[i]->getSpeedBoost() != 0))
										{
											if ((tank_array_[i]->getAngle() == 0) && ((map_o.getCell(ii, jj).pos.y + 13.5) < tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 1) && ((map_o.getCell(ii, jj).pos.x + 13.5) > tank_array_[i]->getObj().pos.x))	a = 0;
											if ((tank_array_[i]->getAngle() == 2) && ((map_o.getCell(ii, jj).pos.y + 13.5) > tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 3) && ((map_o.getCell(ii, jj).pos.x + 13.5) < tank_array_[i]->getObj().pos.x))	a = 0;
										}
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (tank_array_[i]->getSpeedBoost() != 0))
										{
											if ((tank_array_[i]->getAngle() == 0) && ((map_o.getCell(ii, jj).pos.y + 13.5) > tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 1) && ((map_o.getCell(ii, jj).pos.x + 13.5) < tank_array_[i]->getObj().pos.x))	a = 0;
											if ((tank_array_[i]->getAngle() == 2) && ((map_o.getCell(ii, jj).pos.y + 13.5) < tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 3) && ((map_o.getCell(ii, jj).pos.x + 13.5) > tank_array_[i]->getObj().pos.x))	a = 0;
										}
									}
								}
								if ((sprite_buff_t.getGlobalBounds().intersects(sprite_buff.getGlobalBounds(), flrect)) && (map_o.getCell(ii, jj).type == 9))
								{
									if (tank_array_[i]->getPlayer() == 0)
									{
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (tank_array_[i]->getSpeedBoost() != 0))
										{
											if ((tank_array_[i]->getAngle() == 0) && ((map_o.getCell(ii, jj).pos.y + 13.5) < tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 1) && ((map_o.getCell(ii, jj).pos.x + 13.5) > tank_array_[i]->getObj().pos.x))	a = 0;
											if ((tank_array_[i]->getAngle() == 2) && ((map_o.getCell(ii, jj).pos.y + 13.5) > tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 3) && ((map_o.getCell(ii, jj).pos.x + 13.5) < tank_array_[i]->getObj().pos.x))	a = 0;
										}
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (tank_array_[i]->getSpeedBoost() != 0))
										{
											if ((tank_array_[i]->getAngle() == 0) && ((map_o.getCell(ii, jj).pos.y + 13.5) > tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 1) && ((map_o.getCell(ii, jj).pos.x + 13.5) < tank_array_[i]->getObj().pos.x))	a = 0;
											if ((tank_array_[i]->getAngle() == 2) && ((map_o.getCell(ii, jj).pos.y + 13.5) < tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 3) && ((map_o.getCell(ii, jj).pos.x + 13.5) > tank_array_[i]->getObj().pos.x))	a = 0;
										}
									}
									if (tank_array_[i]->getPlayer() == 1)
									{
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (tank_array_[i]->getSpeedBoost() != 0))
										{
											if ((tank_array_[i]->getAngle() == 0) && ((map_o.getCell(ii, jj).pos.y + 13.5) < tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 1) && ((map_o.getCell(ii, jj).pos.x + 13.5) > tank_array_[i]->getObj().pos.x))	a = 0;
											if ((tank_array_[i]->getAngle() == 2) && ((map_o.getCell(ii, jj).pos.y + 13.5) > tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 3) && ((map_o.getCell(ii, jj).pos.x + 13.5) < tank_array_[i]->getObj().pos.x))	a = 0;
										}
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (tank_array_[i]->getSpeedBoost() != 0))
										{
											if ((tank_array_[i]->getAngle() == 0) && ((map_o.getCell(ii, jj).pos.y + 13.5) > tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 1) && ((map_o.getCell(ii, jj).pos.x + 13.5) < tank_array_[i]->getObj().pos.x))	a = 0;
											if ((tank_array_[i]->getAngle() == 2) && ((map_o.getCell(ii, jj).pos.y + 13.5) < tank_array_[i]->getObj().pos.y))	a = 0;
											if ((tank_array_[i]->getAngle() == 3) && ((map_o.getCell(ii, jj).pos.x + 13.5) > tank_array_[i]->getObj().pos.x))	a = 0;
										}
									}
								}
							}
						}
					}
				}
				if (a == 1) { tank_array_[i]->setAccess(1); }
				else { tank_array_[i]->setAccess(0);	break; }
			}
		}
	}
}

void enemys::move_control()
{
	for (size_t i = 0; i < counter_; i++)
	{
		if (tank_array_[i]->getHealth() != 0)
		{
			tank_array_[i]->control();
		}
	}
}

void enemys::fire_control()
{
	for (size_t i = 0; i < counter_; i++)
	{
		if (tank_array_[i]->getHealth() != 0)	tank_array_[i]->fire();
	}
}

void enemys::bonus_control(map &map_o)
{
	if (map_o.getBonuses() > 0)
	{
		for (size_t i = 0; i < counter_; i++)
		{
			if (tank_array_[i]->getPlayer() < 2)
			{
				sf::FloatRect flrect;
				sf::Sprite sprite_buff_t = tank_array_[i]->getSprite();
				int xj = int((tank_array_[i]->getObj().pos.x - 13.5) / 27) - 2;
				int yi = int((tank_array_[i]->getObj().pos.y - 13.5) / 27) - 2;
				for (int ii = yi; ii < (yi + 4); ii++)
				{
					for (int jj = xj; jj < (xj + 4); jj++)
					{
						if ((ii > (-1)) && (ii < 30) && (jj > (-1)) && (jj < 30))
						{
							if (map_o.getCell(ii, jj).type == 10)
							{
								sprite_buff.setPosition(float(map_o.getCell(ii, jj).pos.x), float(map_o.getCell(ii, jj).pos.y));
								if (sprite_buff_t.getGlobalBounds().intersects(sprite_buff.getGlobalBounds(), flrect))
								{
									map_o.setEffect(ii, jj, 3);
									hp_bonus_audio.play();
									map_o.setCellType(ii, jj, 5);
									tank_array_[i]->setHealth(tank_array_[i]->getHealth() + TANK_PLAYER_BONUS_HP);
								}
							}
						}
					}
				}
			}
		}
	}
}

void enemys::draw(int game_status, sf::RenderWindow &window)
{
	for (size_t i = 0; i < counter_; i++)
	{
		if (tank_array_[i]->getHealth() == 0) tank_array_[i]->draw(window);
	}
	for (size_t i = 0; i < counter_; i++)
	{
		for (size_t j = 0; j < tank_array_[i]->getBulletsCounter(); j++)
		{
			if (game_status < 2) tank_array_[i]->getBullets()[j]->draw(window);
		}
	}
	for (size_t i = 0; i < counter_; i++)
	{
		if (tank_array_[i]->getHealth() != 0) tank_array_[i]->draw(window);
	}
}

void enemys::bullet_collision(map &map_o, game &game_o)
{
	for (size_t i = 0; i < counter_; i++)
	{
		for (size_t j = 0; j < tank_array_[i]->getBulletsCounter(); j++)
		{
			if (tank_array_[i]->getBullets()[j]->getStatus() == 1)
			{
				int bull_iy = int(floor((tank_array_[i]->getBullets()[j]->getObj().pos.y) / 27));
				int bull_jx = int(floor((tank_array_[i]->getBullets()[j]->getObj().pos.x) / 27));

				if ((bull_iy > -1) && (bull_iy < 20) && (bull_jx > -1) && (bull_jx < 30))
				{
					if ((map_o.getCell(bull_iy, bull_jx).type) != 0 && (map_o.getCell(bull_iy, bull_jx).health != 0))
					{
						tank_array_[i]->getBullets()[j]->Die();
						if (map_o.getCell(bull_iy, bull_jx).type == 2)
						{
							map_o.Hit(bull_iy, bull_jx);
						}
						if (map_o.getCell(bull_iy, bull_jx).type == 3)
						{
							map_o.Hit(bull_iy, bull_jx);
							if ((map_o.getCell(bull_iy, bull_jx).health == 0)) game_o.Hit(0);
						}
						if (map_o.getCell(bull_iy, bull_jx).type == 4)
						{
							map_o.Hit(bull_iy, bull_jx);
							if ((map_o.getCell(bull_iy, bull_jx).health == 0)) game_o.Hit(1);
						}
					}
				}
			}
		}
	}

	for (size_t i = 0; i < counter_; i++)
	{
		for (size_t j = 0; j < tank_array_[i]->getBulletsCounter(); j++)
		{
			for (size_t k = 0; k < counter_; k++)
			{
				if (i != k)
				{
					if ((tank_array_[k]->getHealth() != 0) && (tank_array_[i]->getBullets()[j]->getStatus() == 1))
					{
						if ((abs(tank_array_[k]->getObj().pos.x - tank_array_[i]->getBullets()[j]->getObj().pos.x) <= 10) && (abs(tank_array_[k]->getObj().pos.y - tank_array_[i]->getBullets()[j]->getObj().pos.y) <= 10) && (tank_array_[k]->getHealth() != 0))
						{
							if (tank_array_[k]->getObj().angle == tank_array_[i]->getBullets()[j]->getObj().angle) tank_array_[k]->Hit(50);
							if (abs(tank_array_[k]->getObj().angle - tank_array_[i]->getBullets()[j]->getObj().angle) == 1) tank_array_[k]->Hit(40);
							if (abs(tank_array_[k]->getObj().angle - tank_array_[i]->getBullets()[j]->getObj().angle) == 3) tank_array_[k]->Hit(40);
							if (abs(tank_array_[k]->getObj().angle - tank_array_[i]->getBullets()[j]->getObj().angle) == 2) tank_array_[k]->Hit(30);
							tank_array_[i]->getBullets()[j]->Die();
							if ((tank_array_[k]->getPlayer() > 1) && (tank_array_[k]->getHealth() == 0)) tank_array_[i]->Bonus();
						}
					}
				}
			}
		}
	}
}

enemys::tank_array enemys::getTanks() const
{
	tank_array temp_array(std::make_unique<tank_ptr[]>(counter_));
	for (size_t i = 0; i < counter_; i++)
	{
		temp_array[i] = tank_array_[i];
	}

	return temp_array;
}
