#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

#include "config.h"
#include "bullet.h"


void bullet::config()
{
	if (type_ == 0)
	{
		TANK_PLAYER_BULLET_STEP = TANK_PLAYER_BALANCE_BULLET_STEP;
		TANK_PLAYER_BULLET_SPEED = TANK_PLAYER_BALANCE_BULLET_SPEED;
		TANK_PLAYER_BULLET_LIFE_TIME = TANK_PLAYER_BALANCE_BULLET_LIFE_TIME;
	}
	if (type_ == 1)
	{
		TANK_PLAYER_BULLET_STEP = TANK_PLAYER_HEAVY_BULLET_STEP;
		TANK_PLAYER_BULLET_SPEED = TANK_PLAYER_HEAVY_BULLET_SPEED;
		TANK_PLAYER_BULLET_LIFE_TIME = TANK_PLAYER_HEAVY_BULLET_LIFE_TIME;
	}
	if (type_ == 2)
	{
		TANK_PLAYER_BULLET_STEP = TANK_PLAYER_LIGHT_BULLET_STEP;
		TANK_PLAYER_BULLET_SPEED = TANK_PLAYER_LIGHT_BULLET_SPEED;
		TANK_PLAYER_BULLET_LIFE_TIME = TANK_PLAYER_LIGHT_BULLET_LIFE_TIME;
	}
	if (type_ == 3)
	{
		TANK_PLAYER_BULLET_STEP = TANK_II_BULLET_STEP;
		TANK_PLAYER_BULLET_SPEED = TANK_II_BULLET_SPEED;
		TANK_PLAYER_BULLET_LIFE_TIME = TANK_II_BULLET_LIFE_TIME;
	}

	width_ = 3;
	height_ = 7;
	texture_ = BULLET_PLAYER_TEXTURE;

	time_fly = 0;
	time_fly_pos = 0;

	explosion_status = 7;
	time_explosion = 0;

	texture_bullet.loadFromFile(BULLET_PLAYER_TEXTURE);

	flag_boom = true;
}

bullet::bullet(double x, double y, int parent, int type, int angle) :
	pos_({x, y}),
	parent_(parent),
	type_(type),
	angle_(angle),
	status_(2)
{ 
	if (angle_ == 0) pos_.y -= 13.5;
	if (angle_ == 1) pos_.x += 13.5;
	if (angle_ == 2) pos_.y += 13.5;
	if (angle_ == 3) pos_.x -= 13.5;
	config();
}

void bullet::draw(sf::RenderWindow &window)
{
	if ((clock() - time_fly) > TANK_PLAYER_BULLET_LIFE_TIME)
	{
		if ((status_ == 3) && (explosion_status > 6)) status_ = 0;
		if (status_ == 1) {	status_ = 3;explosion_status = 0;	}
		if (status_ == 2) status_ = 1;
		time_fly = clock();
	}
	if ((status_ == 1) && (explosion_status > 6))
	{
		if ((clock() - time_fly_pos) > TANK_PLAYER_BULLET_SPEED)
		{
			if (angle_ == 0) pos_.y -= TANK_PLAYER_BULLET_STEP;
			if (angle_ == 1) pos_.x += TANK_PLAYER_BULLET_STEP;
			if (angle_ == 2) pos_.y += TANK_PLAYER_BULLET_STEP;
			if (angle_ == 3) pos_.x -= TANK_PLAYER_BULLET_STEP;

			time_fly_pos = clock();
		}
		sprite_bullet.setTexture(texture_bullet);
		sprite_bullet.setRotation(float(angle_ * 90));
		sprite_bullet.setOrigin(1.5f, 3.5f);
		sprite_bullet.setPosition(float(pos_.x), float(pos_.y));
		window.draw(sprite_bullet);
	}
	else
	{
		explosion_drawing(window);
	}
}

obj_t bullet::getObj()
{
	obj_t objj = { {pos_.x, pos_.y}, 3, 7, angle_ };
	return objj;
}

void bullet::Die()
{
	status_ = 3;
	explosion_status = 0;
}

int bullet::getStatus()
{
	return status_;
}

void bullet::explosion_drawing(sf::RenderWindow &window)
{
	if (explosion_status < 7)
	{
		if ((clock() - time_explosion) > 50)
		{
			explosion_status++;
			time_explosion = clock();
		}
		if ((explosion_status != 0) && (explosion_status != 7))
		{
			sf::Texture texture_e;
			texture_e.loadFromFile(BULLET_COLLISION_TEXTURE + std::to_string(explosion_status) + ".png");
			sf::Sprite sprite_e(texture_e);
			sprite_e.setPosition(float(pos_.x), float(pos_.y));
			sprite_e.setOrigin(13.5f, 13.5f);
			window.draw(sprite_e);
		}
	}
}

void bullet::explosion_draw()
{
	explosion_status = 0;
}


bool bullet::getFlagBoom()
{
	return flag_boom;
}

void bullet::setFlagBoom(bool flag_boom_set)
{
	flag_boom = flag_boom_set;
}
