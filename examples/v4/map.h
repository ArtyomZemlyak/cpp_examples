#ifndef MAP_H
#define MAP_H

#include "base-types.h"
#include "effect.h"

class map
{
public:
	using effect_ptr = std::shared_ptr<effect>;
	using effect_array = std::unique_ptr<effect_ptr[]>;

	map();
	map(int variant);
	~map() = default;

	effect_ptr operator [](size_t rhs) const;

	void draw(sf::RenderWindow &window);
	void Hit(int i, int j);
	void base_Die(int player);
	cell_t getCell(int i, int j);
	int getBonuses();
	void setCellType(int i, int j, int type_c);
	void setEffect(int i, int j, int type_e);
	void drawEffect(sf::RenderWindow &window);
	void DieEffect();


private:
	void config();

	int variant_;
	cell_t cells_[20][30];
	std::string texture_;

	int bonuses_;

	size_t counter_;
	effect_array effect_array_;

	sf::Texture texture_map;
	sf::Texture texture_cells[19];

	sf::Sprite sprite_map;
	sf::Sprite sprite_cells[19];

	sf::Sound broke_cell_audio;			// sound broke of cell
	sf::SoundBuffer broke_cell;
	sf::Sound break_cell_audio;			// sound break of cell
	sf::SoundBuffer break_cell;
	sf::Sound win_one_audio;				// sound of win of player
	sf::SoundBuffer win_one;
	sf::Sound win_two_audio;				// sound of win of player
	sf::SoundBuffer win_two;
	sf::Sound explosion_audio;			// sound of explosion
	sf::SoundBuffer explosion;

};


#endif
