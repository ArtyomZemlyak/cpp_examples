#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <string>

#include "config.h"
#include "map.h"

void map::config()
{
	bonuses_ = 1;

	broke_cell.loadFromFile(SOUND_BUILDING_BROKE);
	broke_cell_audio.setBuffer(broke_cell);
	broke_cell_audio.setVolume(float(30));

	break_cell.loadFromFile(SOUND_BREAK);
	break_cell_audio.setBuffer(break_cell);
	break_cell_audio.setVolume(float(30));

	win_one.loadFromFile(SOUND_PLAYER_ONE_WIN);
	win_one_audio.setBuffer(win_one);
	win_two.loadFromFile(SOUND_PLAYER_TWO_WIN);
	win_two_audio.setBuffer(win_two);

	explosion.loadFromFile(SOUND_BUILDING_BOOM);
	explosion_audio.setBuffer(explosion);
	explosion_audio.setVolume(float(100));

	for (int i = 0; i < 19; i++)
	{
		switch (i)
		{
			case 0:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_NOTHING);
				break;
			case 1:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_NO_BR);
				break;
			case 2:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BR);
				break;
			case 3:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BASE_ONE);
				break;
			case 4:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BASE_TWO);
				break;
			case 5:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_ROAD_DIRTY);
				break;
			case 6:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_GROSS_1);
				break;
			case 7:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_GROSS_2);
				break;
			case 8:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_GROSS_3);
				break;
			case 9:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_ANTITANK);
				break;
			case 10:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BONUS_HP);
				break;
			case 11:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BASE_ONE_BR_1);
				break;
			case 12:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BASE_ONE_BR_2);
				break;
			case 13:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BASE_ONE_BR_FULL);
				break;
			case 14:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BASE_TWO_BR_1);
				break;
			case 15:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BASE_TWO_BR_2);
				break;
			case 16:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BASE_TWO_BR_FULL);
				break;
			case 17:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BR_1);
				break;
			case 18:
				texture_cells[i].loadFromFile(MAP_CELL_TEXTURE_BR_FULL);
				break;
		}
		sprite_cells[i].setTexture(texture_cells[i]);
	}
}

map::map() :
	variant_(0)
{
	config();
}

map::map(int variant) :
	variant_(variant)
{ 
	config();

	if (variant == 0)
	{
		texture_ = MAP_ONE_BG;
		texture_map.loadFromFile(texture_);
		sprite_map.setTexture(texture_map);
		short int cells_var[20][30] = {	//2 - breaking, 1 - not, 3 - base_one, 4 - base_two, 0 - nothing.  x*y = 30*20
					{{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1}}, 
					{{1},{6},{2},{5},{5},{5},{5},{2},{2},{8},{5},{2},{4},{4},{2},{5},{7},{7},{2},{2},{2},{2},{2},{6},{1},{6},{6},{6},{6},{1}},
					{{1},{6},{2},{5},{2},{2},{5},{2},{1},{8},{5},{2},{4},{4},{2},{5},{7},{7},{2},{6},{6},{6},{2},{6},{1},{6},{6},{6},{6},{1}},
					{{1},{2},{2},{5},{2},{6},{5},{2},{1},{8},{5},{2},{2},{2},{2},{5},{2},{2},{2},{2},{2},{5},{2},{6},{1},{2},{2},{2},{2},{1}},
					{{1},{5},{5},{5},{2},{6},{5},{2},{1},{8},{5},{5},{5},{5},{5},{5},{2},{5},{5},{5},{9},{5},{5},{5},{1},{7},{7},{7},{7},{1}},
					{{1},{5},{9},{2},{2},{6},{5},{2},{1},{1},{1},{8},{8},{8},{8},{5},{2},{2},{2},{5},{2},{2},{2},{5},{5},{5},{2},{2},{2},{1}},
					{{1},{5},{9},{8},{8},{6},{5},{2},{2},{2},{2},{9},{9},{9},{1},{5},{2},{1},{2},{5},{5},{5},{5},{5},{5},{5},{2},{8},{7},{1}},
					{{1},{5},{9},{8},{8},{6},{5},{5},{5},{5},{5},{5},{5},{5},{1},{5},{2},{1},{2},{5},{1},{1},{1},{1},{1},{5},{2},{8},{7},{1}},
					{{1},{5},{9},{9},{2},{2},{2},{7},{7},{2},{6},{6},{6},{1},{1},{5},{2},{2},{2},{5},{2},{6},{5},{2},{8},{5},{2},{8},{7},{1}},
					{{1},{5},{5},{9},{8},{8},{8},{7},{1},{2},{6},{6},{6},{1},{2},{5},{5},{5},{5},{5},{2},{6},{5},{2},{1},{5},{8},{8},{7},{1}},
					{{1},{9},{5},{2},{8},{8},{8},{7},{1},{2},{2},{2},{2},{2},{2},{2},{2},{2},{1},{5},{2},{6},{5},{2},{1},{5},{8},{8},{7},{1}},
					{{1},{10},{5},{1},{1},{1},{1},{1},{1},{2},{1},{1},{1},{1},{1},{9},{9},{9},{1},{5},{8},{6},{5},{2},{1},{2},{2},{2},{2},{1}},
					{{1},{2},{5},{2},{2},{1},{8},{5},{5},{5},{5},{5},{5},{5},{5},{5},{8},{8},{1},{5},{8},{6},{5},{9},{1},{1},{5},{5},{5},{1}},
					{{1},{9},{5},{2},{2},{1},{1},{5},{7},{7},{7},{7},{7},{7},{7},{5},{8},{8},{2},{5},{8},{6},{5},{9},{8},{1},{8},{8},{5},{1}},
					{{1},{8},{8},{2},{8},{8},{2},{5},{1},{1},{1},{2},{2},{2},{2},{5},{8},{8},{2},{5},{8},{6},{5},{9},{2},{1},{6},{6},{5},{1}},
					{{1},{8},{8},{8},{8},{8},{1},{5},{5},{5},{5},{5},{5},{5},{5},{5},{8},{2},{2},{5},{8},{6},{5},{2},{2},{1},{6},{6},{5},{1}},
					{{1},{2},{6},{2},{2},{2},{1},{6},{9},{6},{5},{2},{2},{2},{2},{5},{8},{2},{8},{5},{5},{5},{5},{2},{2},{6},{6},{6},{5},{1}},
					{{1},{2},{6},{2},{8},{8},{1},{6},{9},{6},{5},{2},{3},{3},{2},{5},{8},{2},{2},{2},{2},{2},{2},{2},{2},{6},{6},{6},{5},{1}},
					{{1},{2},{6},{2},{8},{8},{1},{6},{9},{6},{5},{2},{3},{3},{2},{5},{5},{5},{5},{5},{5},{5},{5},{5},{5},{5},{5},{5},{5},{1}},
					{{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1}}
		};
		for (int i = 0; i < 20; i++)		//y
		{
			for (int j = 0; j < 30; j++)	//x
			{
				point_t pos = {double(27 * j), double(27 * i)};
				if (cells_var[i][j] == 0) cells_[i][j] = {0, pos, 0, 27, 27, MAP_CELL_TEXTURE_NOTHING};
				if (cells_var[i][j] == 1) cells_[i][j] = {1, pos, CELL_HP, 27, 27, MAP_CELL_TEXTURE_NO_BR};
				if (cells_var[i][j] == 2) cells_[i][j] = {2, pos, CELL_HP, 27, 27, MAP_CELL_TEXTURE_BR};
				if (cells_var[i][j] == 3) cells_[i][j] = {3, pos, BASE_HP, 27, 27, MAP_CELL_TEXTURE_BASE_ONE};
				if (cells_var[i][j] == 4) cells_[i][j] = {4, pos, BASE_HP, 27, 27, MAP_CELL_TEXTURE_BASE_TWO};
				if (cells_var[i][j] == 5) cells_[i][j] = {5, pos, 0, 27, 27, MAP_CELL_TEXTURE_ROAD_DIRTY};
				if (cells_var[i][j] == 6) cells_[i][j] = {6, pos, 0, 27, 27, MAP_CELL_TEXTURE_GROSS_1};
				if (cells_var[i][j] == 7) cells_[i][j] = {7, pos, 0, 27, 27, MAP_CELL_TEXTURE_GROSS_2};
				if (cells_var[i][j] == 8) cells_[i][j] = {8, pos, 0, 27, 27, MAP_CELL_TEXTURE_GROSS_3};
				if (cells_var[i][j] == 9) cells_[i][j] = {9, pos, 0, 27, 27, MAP_CELL_TEXTURE_ANTITANK};
				if (cells_var[i][j] == 10) cells_[i][j] = {10, pos, 0, 27, 27, MAP_CELL_TEXTURE_BONUS_HP};
			}
		}
		for (int i = 0; i < 20; i++)		//y
		{
			for (int j = 0; j < 30; j++)	//x
			{
				if (cells_[i][j].type == 2)
				{
					cells_[i][j].health = rand() % CELL_HP;
					if (cells_[i][j].health == 0) cells_[i][j].health = CELL_HP;
				}
			}
		}
	}
}

map::effect_ptr map::operator [](size_t rhs) const
{
	if (rhs >= counter_)
	{
		throw std::out_of_range("Index is out of range");
	}

	return effect_array_[rhs];
}

void map::draw(sf::RenderWindow &window)
{
	window.draw(sprite_map);
	
	for (int i = 0; i < 20; i++)		//y
	{
		for (int j = 0; j < 30; j++)	//x
		{
			for (int k = 0; k < 19; k++) sprite_cells[k].setPosition(float(cells_[i][j].pos.x), float(cells_[i][j].pos.y));
			if ((cells_[i][j].type == 1) || (cells_[i][j].type == 9) || (cells_[i][j].type == 10))
			window.draw(sprite_cells[cells_[i][j].type]);
			if (cells_[i][j].type == 2)
			{
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BR)	window.draw(sprite_cells[2]);
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BR_1)	window.draw(sprite_cells[17]);
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BR_FULL)	window.draw(sprite_cells[18]);
			}
			if (cells_[i][j].type == 3)
			{
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BASE_ONE)	window.draw(sprite_cells[3]);
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BASE_ONE_BR_1)	window.draw(sprite_cells[11]);
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BASE_ONE_BR_2)	window.draw(sprite_cells[12]);
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BASE_ONE_BR_FULL)	window.draw(sprite_cells[13]);
			}
			if (cells_[i][j].type == 4)
			{
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BASE_TWO)	window.draw(sprite_cells[4]);
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BASE_TWO_BR_1)	window.draw(sprite_cells[14]);
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BASE_TWO_BR_2)	window.draw(sprite_cells[15]);
				if (cells_[i][j].texture == MAP_CELL_TEXTURE_BASE_TWO_BR_FULL)	window.draw(sprite_cells[16]);
			}
		}
	}
}

cell_t map::getCell(int i, int j)
{
	return cells_[i][j];
}

int map::getBonuses()
{
	return bonuses_;
}

void map::Hit(int i, int j)
{
	if (cells_[i][j].health != 0)
	{
		if ((cells_[i][j].type == 3) || (cells_[i][j].type == 4))
		{
			if (cells_[i][j].health > 39) cells_[i][j].health -= 40;
			else cells_[i][j].health = 0;
			if ((cells_[i][j].health < (int(BASE_HP / 3 * 2) + 1)) && (cells_[i][j].type == 3)) { break_cell_audio.play(); setEffect(i, j, 1); cells_[i][j].texture = MAP_CELL_TEXTURE_BASE_ONE_BR_1; }
			if ((cells_[i][j].health < (int(BASE_HP / 3 * 1) + 1)) && (cells_[i][j].type == 3)) { break_cell_audio.play(); setEffect(i, j, 1); cells_[i][j].texture = MAP_CELL_TEXTURE_BASE_ONE_BR_2; }
			if ((cells_[i][j].health == 0) && (cells_[i][j].type == 3)) { explosion_audio.play(); setEffect(i, j, 0); setEffect(i, j, 2);  cells_[i][j].texture = MAP_CELL_TEXTURE_BASE_ONE_BR_FULL; }
			if ((cells_[i][j].health < (int(BASE_HP / 3 * 2) + 1)) && (cells_[i][j].type == 4)) { break_cell_audio.play(); setEffect(i, j, 1); cells_[i][j].texture = MAP_CELL_TEXTURE_BASE_TWO_BR_1; }
			if ((cells_[i][j].health < (int(BASE_HP / 3 * 1) + 1)) && (cells_[i][j].type == 4)) { break_cell_audio.play(); setEffect(i, j, 1); cells_[i][j].texture = MAP_CELL_TEXTURE_BASE_TWO_BR_2; }
			if ((cells_[i][j].health == 0) && (cells_[i][j].type == 4)) { explosion_audio.play(); setEffect(i, j, 0); setEffect(i, j, 2); cells_[i][j].texture = MAP_CELL_TEXTURE_BASE_TWO_BR_FULL; }
		}
		else
		{
			if (cells_[i][j].health > 49) cells_[i][j].health -= 50;
			else cells_[i][j].health = 0;
			if ((cells_[i][j].health < (int(CELL_HP / 2 * 1) + 1)) && (cells_[i][j].type == 2)) { broke_cell_audio.play(); setEffect(i, j, 1); cells_[i][j].texture = MAP_CELL_TEXTURE_BR_1; }
			if ((cells_[i][j].health == 0) && (cells_[i][j].type == 2)) { broke_cell_audio.play(); setEffect(i, j, 0); cells_[i][j].texture = MAP_CELL_TEXTURE_BR_FULL; }
		}
	}
}

void map::base_Die(int player)
{
	if (player == 0)
	{
		short int test_live = 0;
		for (int i = 0; i < 20; i++)		//y
		{
			for (int j = 0; j < 30; j++)	//x
			{
				if ((cells_[i][j].type == 3) && (cells_[i][j].health != 0))
				{
					for (int i = 0; i < 20; i++)		//y
						for (int j = 0; j < 30; j++)	//x
							if ((cells_[i][j].type == 3) && (cells_[i][j].health != 0)) { setEffect(i, j, 0);  setEffect(i, j, 2); }
					test_live = 1;
					cells_[i][j].health = 0;
					if ((cells_[i][j].health == 0) && (cells_[i][j].type == 3)) cells_[i][j].texture = MAP_CELL_TEXTURE_BASE_ONE_BR_FULL;
				}
			}
		}
		if (test_live == 1)
		{
			explosion_audio.play();
			win_two_audio.play();
		}
	}
	if (player == 1)
	{
		short int test_live = 0;
		for (int i = 0; i < 20; i++)		//y
		{
			for (int j = 0; j < 30; j++)	//x
			{
				if ((cells_[i][j].type == 4) && (cells_[i][j].health != 0))
				{
					for (int i = 0; i < 20; i++)		//y
						for (int j = 0; j < 30; j++)	//x
							if ((cells_[i][j].type == 4) && (cells_[i][j].health != 0)) { setEffect(i, j, 0); setEffect(i, j, 2); }
					test_live = 1;
					cells_[i][j].health = 0;
					if ((cells_[i][j].health == 0) && (cells_[i][j].type == 4)) cells_[i][j].texture = MAP_CELL_TEXTURE_BASE_TWO_BR_FULL;
				}
			}
		}
		if (test_live == 1)
		{
			explosion_audio.play();
			win_one_audio.play();
		}
	}
}

void map::setCellType(int i, int j, int type_c)
{
	if (cells_[i][j].type == 10) bonuses_--;
	cells_[i][j].type = type_c;
}

void map::setEffect(int i, int j, int type_e)
{
	double x = j * 27 + 13.5;
	double y = i * 27 + 13.5;
	effect temp_effect(x, y, type_e);
	map::effect_ptr part = std::make_shared<effect>(temp_effect);
	effect_array temp_array(std::make_unique<effect_ptr[]>(counter_ + 1));
	for (size_t i = 0; i < counter_; i++)
	{
		temp_array[i] = effect_array_[i];
	}
	temp_array[counter_] = part;
	counter_++;
	effect_array_.swap(temp_array);
}

void map::drawEffect(sf::RenderWindow &window)
{
	for (size_t i = 0; i < counter_; i++)
	{
		effect_array_[i]->draw(window);
	}
}

void map::DieEffect()
{
	for (size_t i = 0; i < counter_; i++)
	{
		if (effect_array_[i]->getStatus() == 2)
		{
			for (size_t j = i; j < counter_ - 1; j++)
			{
				effect_array_[j] = effect_array_[j + 1];
			}
			effect_array_[counter_ - 1] = nullptr;
			counter_--;
		}
	}
}
