#ifndef TANK_H
#define TANK_H

#include "base-types.h"
#include "bullet.h"


class tank
{
public:
	using bullet_ptr = std::shared_ptr<bullet>;
	using bullet_array = std::unique_ptr<bullet_ptr[]>;


	tank();
	tank(int player, int type);
	tank(const tank& origin);
	~tank() = default;

	bullet_ptr operator [](size_t rhs) const;

	void draw(sf::RenderWindow &window);
	void control();
	void fire();
	void Bonus();
	void Die();
	void Hit(int damage);
	int getAngle();
	obj_t getObj();
	int getPlayer();
	int getHealth();
	bullet_array getBullets() const;
	size_t getBulletsCounter();
	sf::Sprite getSprite();
	int getStatusII();
	int getSpeedBoost();
	void setAccess(bool access_set);
	void setHealth(int health_set);

private:
	void config();
	void shot_drawing(sf::RenderWindow &window);
	void explosion_drawing(sf::RenderWindow &window);
	void setTexture();

	size_t counter_;
	bullet_array bullet_array_;

	int player_;
	int type_;
	int health_;
	point_t pos_;
	double width_;
	double height_;
	int angle_;
	std::string texture_;

	double bonus;
	int speed_boost;

	sf::Texture texture_tank;
	sf::Sprite sprite_tank;

	int TANK_PLAYER_HP;
	int TANK_PLAYER_ROTATE_DELAY;
	int TANK_PLAYER_MOVE_DELAY_MIN;
	int TANK_PLAYER_MOVE_DELAY_MAX;
	int	TANK_PLAYER_ACCELERATION_DELAY;
	int	TANK_PLAYER_ACCELERATION_SPEED;
	int	TANK_PLAYER_CONTROL_DELAY_ANOTHER;
	int	TANK_PLAYER_ATACK_SPEED;

	long int time_anim;
	long int time_key_WS;
	long int time_key_AD;
	long int time_key_Fire;
	long int time_Hit;
	long int time_shot;
	long int time_explosion;
	long int time_speed_boost;
	
	int shot_status;
	int explosion_status;

	int path_II[12];
	int path_II_i;
	int path_II_j;

	bool access;

	sf::Sound shot_audio;										// sound of shot
	sf::SoundBuffer shot;
	sf::Sound explosion_audio;							// sound of explosion
	sf::SoundBuffer explosion;
	sf::Sound boom_audio;										// sound of collision
	sf::SoundBuffer boom;
};


#endif
