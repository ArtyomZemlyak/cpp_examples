#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

#include "config.h"
#include "tank.h"

void tank::config()
{
	if (type_ == 0)
	{
		TANK_PLAYER_HP = TANK_PLAYER_BALANCE_HP;
		TANK_PLAYER_ROTATE_DELAY = TANK_PLAYER_BALANCE_ROTATE_DELAY;
		TANK_PLAYER_MOVE_DELAY_MIN = TANK_PLAYER_BALANCE_MOVE_DELAY_MIN;
		TANK_PLAYER_MOVE_DELAY_MAX = TANK_PLAYER_BALANCE_MOVE_DELAY_MAX;
		TANK_PLAYER_ACCELERATION_DELAY = TANK_PLAYER_BALANCE_ACCELERATION_DELAY;
		TANK_PLAYER_ACCELERATION_SPEED = TANK_PLAYER_BALANCE_ACCELERATION_SPEED;
		TANK_PLAYER_CONTROL_DELAY_ANOTHER = TANK_PLAYER_BALANCE_CONTROL_DELAY_ANOTHER;
		TANK_PLAYER_ATACK_SPEED = TANK_PLAYER_BALANCE_ATACK_SPEED;
	}
	if (type_ == 1)
	{
		TANK_PLAYER_HP = TANK_PLAYER_HEAVY_HP;
		TANK_PLAYER_ROTATE_DELAY = TANK_PLAYER_HEAVY_ROTATE_DELAY;
		TANK_PLAYER_MOVE_DELAY_MIN = TANK_PLAYER_HEAVY_MOVE_DELAY_MIN;
		TANK_PLAYER_MOVE_DELAY_MAX = TANK_PLAYER_HEAVY_MOVE_DELAY_MAX;
		TANK_PLAYER_ACCELERATION_DELAY = TANK_PLAYER_HEAVY_ACCELERATION_DELAY;
		TANK_PLAYER_ACCELERATION_SPEED = TANK_PLAYER_HEAVY_ACCELERATION_SPEED;
		TANK_PLAYER_CONTROL_DELAY_ANOTHER = TANK_PLAYER_HEAVY_CONTROL_DELAY_ANOTHER;
		TANK_PLAYER_ATACK_SPEED = TANK_PLAYER_HEAVY_ATACK_SPEED;
	}
	if (type_ == 2)
	{
		TANK_PLAYER_HP = TANK_PLAYER_LIGHT_HP;
		TANK_PLAYER_ROTATE_DELAY = TANK_PLAYER_LIGHT_ROTATE_DELAY;
		TANK_PLAYER_MOVE_DELAY_MIN = TANK_PLAYER_LIGHT_MOVE_DELAY_MIN;
		TANK_PLAYER_MOVE_DELAY_MAX = TANK_PLAYER_LIGHT_MOVE_DELAY_MAX;
		TANK_PLAYER_ACCELERATION_DELAY = TANK_PLAYER_LIGHT_ACCELERATION_DELAY;
		TANK_PLAYER_ACCELERATION_SPEED = TANK_PLAYER_LIGHT_ACCELERATION_SPEED;
		TANK_PLAYER_CONTROL_DELAY_ANOTHER = TANK_PLAYER_LIGHT_CONTROL_DELAY_ANOTHER;
		TANK_PLAYER_ATACK_SPEED = TANK_PLAYER_LIGHT_ATACK_SPEED;
	}

	if (player_ == 0)
	{
		health_ = TANK_PLAYER_HP;
		pos_ = SPAUN_ONE;
		angle_ = 0;
		texture_ = TANK_PLAYER_TEXTURE_0_0;
	}
	if (player_ == 1)
	{
		health_ = TANK_PLAYER_HP;
		pos_ = SPAUN_TWO;
		angle_ = 2;
		texture_ = TANK_PLAYER_TEXTURE_1_0;
	}
	if (player_ == 2)
	{
		health_ = TANK_II_HP;
		pos_ = SPAUN_THREE;
		angle_ = 1;
		texture_ = TANK_II_TEXTURE_0;
		int path_II_buff[12] = { 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2 };
		for (int i = 0; i < 12; i++) path_II[i] = path_II_buff[i];
		path_II_i = 0;
		path_II_j = 0;
	}
	if (player_ == 3)
	{
		health_ = TANK_II_HP;
		pos_ = SPAUN_FOUR;
		angle_ = 3;
		texture_ = TANK_II_TEXTURE_0;
		int path_II_buff[12] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
		for (int i = 0; i < 12; i++) path_II[i] = path_II_buff[i];
		path_II_i = 0;
		path_II_j = 0;
	}
	if (player_ == 4)
	{
		health_ = TANK_II_HP;
		pos_ = SPAUN_FIVE;
		angle_ = 3;
		texture_ = TANK_II_TEXTURE_0;
		int path_II_buff[12] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
		for (int i = 0; i < 12; i++) path_II[i] = path_II_buff[i];
		path_II_i = 0;
		path_II_j = 0;
	}
	width_, height_ = 27;

	bonus = 1;
	speed_boost = 0;
	time_speed_boost = 0;

	shot.loadFromFile(SOUND_SHOT);
	shot_audio.setBuffer(shot);
	if (player_ < 2) shot_audio.setVolume(float(30));
	else shot_audio.setVolume(float(10));

	explosion.loadFromFile(SOUND_EXPLOSION);
	explosion_audio.setBuffer(explosion);
	explosion_audio.setVolume(float(100));

	boom.loadFromFile(SOUND_BOOM);
	boom_audio.setBuffer(boom);
	if (player_ < 2) boom_audio.setVolume(float(30));
	else boom_audio.setVolume(float(10));

	time_anim = 0;
	time_key_WS = 0;
	time_key_AD = 0;

	time_key_Fire = clock() + player_*(250);
	time_Hit = 0;

	texture_tank.loadFromFile(texture_);
	sprite_tank.setTexture(texture_tank);

	time_shot = 0;
	shot_status = 5;

	time_explosion = 0;
	explosion_status = 10;
}

tank::tank() :
	counter_(0)
{
	config();
}

tank::tank(int player, int type) :
	type_(type),
	player_(player),
	counter_(0)
{ 
	config();
}

tank::tank(const tank& origin) :
	counter_(origin.counter_),
	player_(origin.player_),
	type_(origin.type_),
	bullet_array_(std::make_unique<bullet_ptr[]>(origin.counter_))
{
	config();
	for (size_t i = 0; i < counter_; i++)
	{
		bullet_array_[i] = origin.bullet_array_[i];
	}
}

tank::bullet_ptr tank::operator [](size_t rhs) const
{
	if (rhs >= counter_)
	{
		throw std::out_of_range("Index is out of range");
	}

	return bullet_array_[rhs];
}


void tank::draw(sf::RenderWindow &window)
{
	sprite_tank.setPosition(float(pos_.x), float(pos_.y));
	sprite_tank.setScale(float(0.6), float(0.8));
	sprite_tank.setRotation(float(angle_ * 90));
	sprite_tank.setOrigin(13.5f, 15.5f);
	window.draw(sprite_tank);
	shot_drawing(window);
	explosion_drawing(window);
}

void tank::control()
{
	if (health_ != 0)
	{
		if (player_ == 0)
		{
			if ((clock() - time_key_AD) > (TANK_PLAYER_ROTATE_DELAY))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					angle_--;
					if (angle_ == -1)
						angle_ = 3;
					time_key_AD = clock();
					time_key_WS = clock() - TANK_PLAYER_CONTROL_DELAY_ANOTHER;
					speed_boost = int(speed_boost / 10 * 6);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					angle_++;
					if (angle_ == 4)
						angle_ = 0;
					time_key_AD = clock();
					time_key_WS = clock() - TANK_PLAYER_CONTROL_DELAY_ANOTHER;
					speed_boost = int(speed_boost / 10 * 6);
				}

			}
			if ((clock() - time_key_WS) > TANK_PLAYER_MOVE_DELAY_MIN - speed_boost)
			{
				if (((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || speed_boost != 0) && (access != 0))
				{
					if (angle_ == 0) pos_.y -= TANK_MOVE_STEP;
					if (angle_ == 1) pos_.x += TANK_MOVE_STEP;
					if (angle_ == 2) pos_.y += TANK_MOVE_STEP;
					if (angle_ == 3) pos_.x -= TANK_MOVE_STEP;
					time_key_WS = clock();
				}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (access != 0))
				{
					if (speed_boost == 0)
					{
						if (angle_ == 0) pos_.y += TANK_MOVE_STEP;
						if (angle_ == 1) pos_.x -= TANK_MOVE_STEP;
						if (angle_ == 2) pos_.y -= TANK_MOVE_STEP;
						if (angle_ == 3) pos_.x += TANK_MOVE_STEP;
					}
					time_key_WS = clock();
				}
			}
			if ((clock() - time_speed_boost) > (TANK_PLAYER_ACCELERATION_DELAY + speed_boost))
			{
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (access != 0))
				{
					if (speed_boost == 0) speed_boost = 1;
					if ((TANK_PLAYER_MOVE_DELAY_MIN - speed_boost) > TANK_PLAYER_MOVE_DELAY_MAX) 
						speed_boost += TANK_PLAYER_ACCELERATION_SPEED;
				}
				else
				{
					if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (access != 0))
					{
						if (speed_boost > 0)
							speed_boost -= TANK_PLAYER_ACCELERATION_SPEED * 6;
						if (speed_boost < 0) speed_boost = 0;
					}
					else
					{
						speed_boost -= TANK_PLAYER_ACCELERATION_SPEED;
						if (speed_boost < 0) speed_boost = 0;
						if (access == 0) speed_boost = 0;
					}
				}
				time_speed_boost = clock();
			}
		}

		if (player_ == 1)
		{
			if ((clock() - time_key_AD) > (TANK_PLAYER_ROTATE_DELAY))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					angle_--;
					if (angle_ == -1)
						angle_ = 3;
					time_key_AD = clock();
					time_key_WS = clock() - TANK_PLAYER_CONTROL_DELAY_ANOTHER;
					speed_boost = int(speed_boost / 10 * 6);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					angle_++;
					if (angle_ == 4)
						angle_ = 0;
					time_key_AD = clock();
					time_key_WS = clock() - TANK_PLAYER_CONTROL_DELAY_ANOTHER;
					speed_boost = int(speed_boost / 10 * 6);
				}

			}
			if ((clock() - time_key_WS) > TANK_PLAYER_MOVE_DELAY_MIN - speed_boost)
			{
				if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || speed_boost != 0) && (access != 0))
				{
					if (angle_ == 0) pos_.y -= TANK_MOVE_STEP;
					if (angle_ == 1) pos_.x += TANK_MOVE_STEP;
					if (angle_ == 2) pos_.y += TANK_MOVE_STEP;
					if (angle_ == 3) pos_.x -= TANK_MOVE_STEP;
					time_key_WS = clock();
				}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (access != 0))
				{
					if (speed_boost == 0)
					{
						if (angle_ == 0) pos_.y += TANK_MOVE_STEP;
						if (angle_ == 1) pos_.x -= TANK_MOVE_STEP;
						if (angle_ == 2) pos_.y -= TANK_MOVE_STEP;
						if (angle_ == 3) pos_.x += TANK_MOVE_STEP;
					}
					time_key_WS = clock();
				}
			}
			if ((clock() - time_speed_boost) > (TANK_PLAYER_ACCELERATION_DELAY + speed_boost))
			{
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (access != 0))
				{
					if (speed_boost == 0) speed_boost = 1;
					if ((TANK_PLAYER_MOVE_DELAY_MIN - speed_boost) > TANK_PLAYER_MOVE_DELAY_MAX)
						speed_boost += TANK_PLAYER_ACCELERATION_SPEED;
				}
				else
				{
					if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (access != 0))
					{
						if (speed_boost > 0)
							speed_boost -= TANK_PLAYER_ACCELERATION_SPEED * 6;
						if (speed_boost < 0) speed_boost = 0;
					}
					else
					{
						speed_boost -= TANK_PLAYER_ACCELERATION_SPEED;
						if (speed_boost < 0) speed_boost = 0;
						if (access == 0) speed_boost = 0;
					}
				}
				time_speed_boost = clock();
			}
		}

		if (player_ > 1)
		{
			bool flag_move = false;
			if ((path_II[path_II_i] == 0) && (access != 0))
			{
				if ((clock() - time_key_WS) > TANK_II_MOVE_DELAY_MIN)
				{
					if (angle_ == 0) pos_.y -= TANK_MOVE_STEP;
					if (angle_ == 1) pos_.x += TANK_MOVE_STEP;
					if (angle_ == 2) pos_.y += TANK_MOVE_STEP;
					if (angle_ == 3) pos_.x -= TANK_MOVE_STEP;
					path_II_j++;
					flag_move = true;
					time_key_WS = clock();
				}
			}
			if (path_II[path_II_i] == 1)
			{
				if ((clock() - time_key_AD) > TANK_II_ROTATE)
				{
					angle_--;
					if (angle_ == -1)
						angle_ = 3;
					flag_move = true;
					time_key_AD = clock();
				}
			}
			if (path_II[path_II_i] == 2)
			{
				if ((clock() - time_key_AD) > TANK_II_ROTATE)
				{
					angle_++;
					if (angle_ == 4)
						angle_ = 0;
					flag_move = true;
					time_key_AD = clock();
				}
			}
			if (flag_move == true)
			{
				if (path_II[path_II_i] != 0)
				{
					path_II_i++;
					path_II_j = 0;
				}
				else
				{
					if (path_II_j == int(27 / TANK_MOVE_STEP))
					{
						path_II_i++;
						path_II_j = 0;
					}
				}
				if (path_II_i == 12) path_II_i = 0;
			}
		}
	}
}

void tank::fire()
{
	for (size_t i = 0; i < counter_; i++)
	{
		if ((bullet_array_[i]->getStatus() == 3) && (bullet_array_[i]->getFlagBoom() == true))
		{
			bullet_array_[i]->setFlagBoom(false);
			boom_audio.play();
		}
		if (bullet_array_[i]->getStatus() == 0)
		{
			for (size_t j = i; j < counter_ - 1; j++)
			{
				bullet_array_[j] = bullet_array_[j + 1];
			}
			bullet_array_[counter_ - 1] = nullptr;
			counter_--;
		}
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && player_ == 0)
	{
		if ((clock() - time_key_Fire) > int(TANK_PLAYER_ATACK_SPEED/bonus))
		{
			shot_audio.play();
			bullet temp_bullet(pos_.x, pos_.y, player_, type_, angle_);
			tank::bullet_ptr part = std::make_shared<bullet>(temp_bullet);
			bullet_array temp_array(std::make_unique<bullet_ptr[]>(counter_ + 1));
			for (size_t i = 0; i < counter_; i++)
			{
				temp_array[i] = bullet_array_[i];
			}
			temp_array[counter_] = part;
			counter_++;
			bullet_array_.swap(temp_array);
			shot_status = 0;

			time_key_Fire = clock();
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) && player_ == 1)
	{
		if ((clock() - time_key_Fire) > int(TANK_PLAYER_ATACK_SPEED/bonus))
		{
			shot_audio.play();
			bullet temp_bullet(pos_.x, pos_.y, player_, type_, angle_);
			tank::bullet_ptr part = std::make_shared<bullet>(temp_bullet);
			bullet_array temp_array(std::make_unique<bullet_ptr[]>(counter_ + 1));
			for (size_t i = 0; i < counter_; i++)
			{
				temp_array[i] = bullet_array_[i];
			}
			temp_array[counter_] = part;
			counter_++;
			bullet_array_.swap(temp_array);
			shot_status = 0;

			time_key_Fire = clock();
		}
	}
	if (player_ > 1)
	{
		if ((clock() - time_key_Fire) > TANK_II_ATACK_SPEED)
		{
			shot_audio.play();
			bullet temp_bullet(pos_.x, pos_.y, player_, type_, angle_);
			tank::bullet_ptr part = std::make_shared<bullet>(temp_bullet);
			bullet_array temp_array(std::make_unique<bullet_ptr[]>(counter_ + 1));
			for (size_t i = 0; i < counter_; i++)
			{
				temp_array[i] = bullet_array_[i];
			}
			temp_array[counter_] = part;
			counter_++;
			bullet_array_.swap(temp_array);
			shot_status = 0;

			time_key_Fire = clock();
		}
	}
}

int tank::getAngle()
{
	return angle_;
}

obj_t tank::getObj()
{
	obj_t objj = { {pos_.x, pos_.y}, 3, 7, angle_ };
	return objj;
}

int tank::getPlayer()
{
	return player_;
}

void tank::Bonus()
{
	bonus += TANK_PLAYER_BONUS_ATACK_SPEED;
}

void tank::Die()
{
	if (health_ != 0)
	{
		health_ = 0;
		setTexture();
		explosion_audio.play();
		explosion_status = 0;
	}
}

void tank::Hit(int damage)
{
	if (((clock() - time_Hit) > (10)) && (health_ != 0))
	{
		if (health_ > (damage - 1)) health_ -= damage;
		else health_ = 0;

		setTexture();

		if (health_ == 0) { explosion_status = 0; explosion_audio.play(); Die(); }

		time_Hit = clock();
	}
}

int tank::getHealth()
{
	return health_;
}

tank::bullet_array tank::getBullets() const
{
	bullet_array temp_array(std::make_unique<bullet_ptr[]>(counter_));
	for (size_t i = 0; i < counter_; i++)
	{
		temp_array[i] = bullet_array_[i];
	}

	return temp_array;
}

size_t tank::getBulletsCounter()
{
	return counter_;
}

sf::Sprite tank::getSprite()
{
	return sprite_tank;
}

void tank::setAccess(bool access_set)
{
	access = access_set;
}

void tank::setHealth(int health_set)
{
	health_ = health_set;
	setTexture();
}

void	tank::setTexture()
{
	if ((health_ > 99) && (player_ == 0)) texture_ = TANK_PLAYER_TEXTURE_0_0;
	if ((health_ < (int(TANK_PLAYER_HP / 4 * 3) + 1)) && (player_ == 0)) texture_ = TANK_PLAYER_TEXTURE_0_1;
	if ((health_ < (int(TANK_PLAYER_HP / 4 * 2) + 1)) && (player_ == 0)) texture_ = TANK_PLAYER_TEXTURE_0_2;
	if ((health_ < (int(TANK_PLAYER_HP / 4 * 1) + 1)) && (player_ == 0)) texture_ = TANK_PLAYER_TEXTURE_0_3;
	if ((health_ == 0) && (player_ == 0)) texture_ = TANK_PLAYER_TEXTURE_0_4;
	if ((health_ > 99) && (player_ == 1)) texture_ = TANK_PLAYER_TEXTURE_1_0;
	if ((health_ < (int(TANK_PLAYER_HP / 4 * 3) + 1)) && (player_ == 1)) texture_ = TANK_PLAYER_TEXTURE_1_1;
	if ((health_ < (int(TANK_PLAYER_HP / 4 * 2) + 1)) && (player_ == 1)) texture_ = TANK_PLAYER_TEXTURE_1_2;
	if ((health_ < (int(TANK_PLAYER_HP / 4 * 1) + 1)) && (player_ == 1)) texture_ = TANK_PLAYER_TEXTURE_1_3;
	if ((health_ == 0) && (player_ == 1)) texture_ = TANK_PLAYER_TEXTURE_1_4;
	if ((health_ < (int(TANK_II_HP / 4 * 3) + 1)) && (player_ == 2)) texture_ = TANK_II_TEXTURE_1;
	if ((health_ < (int(TANK_II_HP / 4 * 2) + 1)) && (player_ == 2)) texture_ = TANK_II_TEXTURE_2;
	if ((health_ < (int(TANK_II_HP / 4 * 1) + 1)) && (player_ == 2)) texture_ = TANK_II_TEXTURE_3;
	if ((health_ == 0) && (player_ == 2)) texture_ = TANK_II_TEXTURE_4;
	if ((health_ < (int(TANK_II_HP / 4 * 3) + 1)) && (player_ == 3)) texture_ = TANK_II_TEXTURE_1;
	if ((health_ < (int(TANK_II_HP / 4 * 2) + 1)) && (player_ == 3)) texture_ = TANK_II_TEXTURE_2;
	if ((health_ < (int(TANK_II_HP / 4 * 1) + 1)) && (player_ == 3)) texture_ = TANK_II_TEXTURE_3;
	if ((health_ == 0) && (player_ == 3)) texture_ = TANK_II_TEXTURE_4;
	if ((health_ < (int(TANK_II_HP / 4 * 3) + 1)) && (player_ == 4)) texture_ = TANK_II_TEXTURE_1;
	if ((health_ < (int(TANK_II_HP / 4 * 2) + 1)) && (player_ == 4)) texture_ = TANK_II_TEXTURE_2;
	if ((health_ < (int(TANK_II_HP / 4 * 1) + 1)) && (player_ == 4)) texture_ = TANK_II_TEXTURE_3;
	if ((health_ == 0) && (player_ == 4)) texture_ = TANK_II_TEXTURE_4;
	texture_tank.loadFromFile(texture_);
	sprite_tank.setTexture(texture_tank);
}

void tank::shot_drawing(sf::RenderWindow &window)
{
	if ((shot_status < 5) && (health_ != 0))
	{
		if ((clock() - time_shot) > 50)
		{
			shot_status++;
			time_shot = clock();
		}
		if ((shot_status != 0) && (shot_status != 5))
		{
			sf::Texture texture_s;
			texture_s.loadFromFile(TANK_SHOT_TEXTURE + std::to_string(shot_status) + ".png");
			sf::Sprite sprite_s(texture_s);
			double delt = 10.0;
			if (angle_ == 0) sprite_s.setPosition(float(pos_.x), float(pos_.y - delt));
			if (angle_ == 1) sprite_s.setPosition(float(pos_.x + delt), float(pos_.y));
			if (angle_ == 2) sprite_s.setPosition(float(pos_.x), float(pos_.y + delt));
			if (angle_ == 3) sprite_s.setPosition(float(pos_.x - delt), float(pos_.y));
			sprite_s.setRotation(float(angle_ * 90));
			sprite_s.setOrigin(13.5f, 13.5f);
			window.draw(sprite_s);
		}
	}
}

void tank::explosion_drawing(sf::RenderWindow &window)
{
	if (explosion_status < 10)
	{
		if ((clock() - time_explosion) > 100)
		{
			explosion_status++;
			time_explosion = clock();
		}
		if ((explosion_status != 0) && (explosion_status != 10))
		{
			sf::Texture texture_b;
			texture_b.loadFromFile(MAP_BROKE_TEXTURE + std::to_string(explosion_status) + ".png");
			sf::Sprite sprite_b(texture_b);
			sprite_b.setPosition(float(pos_.x), float(pos_.y));
			sprite_b.setOrigin(27.0f, 27.0f);
			window.draw(sprite_b);
			sf::Texture texture_e;
			texture_e.loadFromFile(TANK_EXPLOSION_TEXTURE + std::to_string(explosion_status) + ".png");
			sf::Sprite sprite_e(texture_e);
			sprite_e.setPosition(float(pos_.x), float(pos_.y));
			sprite_e.setOrigin(13.5f, 13.5f);
			window.draw(sprite_e);
		}
	}
}

int tank::getStatusII()
{
	return path_II[path_II_i];
}

int tank::getSpeedBoost()
{
	return speed_boost;
}