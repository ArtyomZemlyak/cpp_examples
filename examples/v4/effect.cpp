#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

#include "config.h"
#include "effect.h"


void effect::config()
{
	status = 0;
	switch (type_)
	{
	case 0:
		effect_status = 10;
		time_animation = 100;
		break;
	case 1:
		effect_status = 10;
		time_animation = 70;
		break;
	case 2:
		effect_status = 13;
		time_animation = 70;
		break;
	case 3:
		effect_status = 16;
		time_animation = 30;
		break;
	}
	effect_status_max = effect_status;
	time_effect = 0;
}

effect::effect(double x, double y, int type_e) :
	pos_({x, y}),
	type_(type_e)
{
	config();
	effect_status = 0;
}

void effect::draw(sf::RenderWindow &window)
{
	if (status == 0)
	{
		status = 1;
	}

	switch (type_)
	{
		case 0:
			if (effect_status < effect_status_max)
			{
				if ((clock() - time_effect) > time_animation)
				{
					effect_status++;
					if (effect_status == effect_status_max) status = 2;
					time_effect = clock();
				}
				if ((effect_status != 0) && (effect_status != effect_status_max))
				{
					sf::Texture texture_b;
					texture_b.loadFromFile(MAP_BROKE_TEXTURE + std::to_string(effect_status) + ".png");
					sf::Sprite sprite_b(texture_b);
					sprite_b.setPosition(float(pos_.x), float(pos_.y));
					sprite_b.setOrigin(27.0f, 27.0f);
					window.draw(sprite_b);
					sf::Texture texture_e;
				}
			}
			break;
		case 1:
			if (effect_status < effect_status_max)
			{
				if ((clock() - time_effect) > time_animation)
				{
					effect_status++;
					if (effect_status == effect_status_max) status = 2;
					time_effect = clock();
				}
				if ((effect_status != 0) && (effect_status != effect_status_max))
				{
					sf::Texture texture_b;
					texture_b.loadFromFile(MAP_BROKE_TEXTURE + std::to_string(effect_status) + ".png");
					sf::Sprite sprite_b(texture_b);
					sprite_b.setPosition(float(pos_.x), float(pos_.y));
					sprite_b.setScale(float(0.7), float(0.7));
					sprite_b.rotate(90);
					sprite_b.setOrigin(27.0f, 27.0f);
					window.draw(sprite_b);
					sf::Texture texture_e;
				}
			}
			break;
		case 2:
			if (effect_status < effect_status_max)
			{
				if ((clock() - time_effect) > time_animation)
				{
					effect_status++;
					if (effect_status == effect_status_max) status = 2;
					time_effect = clock();
				}
				if ((effect_status != 0) && (effect_status != effect_status_max))
				{
					sf::Texture texture_b;
					texture_b.loadFromFile(BIG_BOOM_TEXTURE + std::to_string(effect_status) + ".png");
					sf::Sprite sprite_b(texture_b);
					sprite_b.setPosition(float(pos_.x), float(pos_.y));
					sprite_b.setScale(float(0.15), float(0.15));
					sprite_b.setOrigin(150.0f, 150.0f);
					window.draw(sprite_b);
					sf::Texture texture_e;
				}
			}
			break;
		case 3:
			if (effect_status < effect_status_max)
			{
				if ((clock() - time_effect) > time_animation)
				{
					effect_status++;
					if (effect_status == effect_status_max) status = 2;
					time_effect = clock();
				}
				if ((effect_status != 0) && (effect_status != effect_status_max))
				{
					sf::Texture texture_b;
					texture_b.loadFromFile(BONUS_TEXTURE + std::to_string(effect_status) + ".png");
					sf::Sprite sprite_b(texture_b);
					sprite_b.setPosition(float(pos_.x), float(pos_.y));
					sprite_b.setScale(float(0.23), float(0.23));
					sprite_b.setOrigin(100.0f, 100.0f);
					window.draw(sprite_b);
					sf::Texture texture_e;
				}
			}
			break;
	}
}

int effect::getStatus()
{
	return status;
}

