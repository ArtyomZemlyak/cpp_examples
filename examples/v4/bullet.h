#ifndef BULLET_H
#define BULLET_H

#include "base-types.h"


class bullet
{
public:
	bullet(double x, double y, int parent, int type, int angle);
	~bullet() = default;

	void draw(sf::RenderWindow &window);
	void Die();
	void explosion_drawing(sf::RenderWindow &window);
	void explosion_draw();
	obj_t getObj();
	int getStatus();
	bool getFlagBoom();
	void setFlagBoom(bool flag_boom_set);

private:
	void config();

	short int status_;
	point_t pos_;
	double width_;
	double height_;
	int angle_;
	int parent_;
	int type_;
	std::string texture_;

	bool flag_boom;

	sf::Texture texture_bullet;
	sf::Sprite sprite_bullet;

	int TANK_PLAYER_BULLET_STEP;
	int TANK_PLAYER_BULLET_SPEED;
	int TANK_PLAYER_BULLET_LIFE_TIME;

	short int explosion_status;
	long int time_explosion;

	long int time_fly;
	long int time_fly_pos;

};


#endif
