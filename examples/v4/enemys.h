#ifndef ENEMYS_H
#define ENEMYS_H

#include "base-types.h"
#include "tank.h"
#include "map.h"
#include "game.h"


class enemys
{
public:
	using tank_ptr = std::shared_ptr<tank>;
	using tank_array = std::unique_ptr<tank_ptr[]>;

	enemys();
	~enemys() = default;

	tank_ptr operator [](size_t rhs) const;

	void initialize(game &game_o);
	void access_path(map &map_o);
	void move_control();
	void bonus_control(map &map_o);
	void fire_control();
	void draw(int game_status, sf::RenderWindow &window);
	void bullet_collision(map &map_o, game &game_o);
	tank_array getTanks() const;

private:
	void config();

	size_t counter_;
	tank_array tank_array_;

	sf::Texture texture_buff;
	sf::Sprite sprite_buff;

	sf::Sound hp_bonus_audio;			// sound of explosion
	sf::SoundBuffer hp_bonus;

};


#endif
