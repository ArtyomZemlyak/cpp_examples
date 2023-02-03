#ifndef GAME_H
#define GAME_H

#include "base-types.h"


class game
{
public:
	game(int status);

	void draw(sf::RenderWindow &window);
	void Hit(int player);
	int status(int health_one, int health_two);
	void text_win(int status, sf::RenderWindow &window);
	int getType(int player);
	void setStatus(int status_set);

private:
	void config();

	int health_one_;
	int health_two_;
	int type_one_;
	int type_two_;
	int status_;										// 1 - game, 2 - end game;

	sf::Texture texture_hp_one;			// health bar of one player
	sf::Texture texture_hp_bg_one;
	sf::Texture texture_hp_two;			// health bar of two player
	sf::Texture texture_hp_bg_two;
	sf::Texture texture_menu_bg;		// bg menu
	sf::Texture texture_end_bg;			// bg end of game

	sf::Sprite sprite_hp_one;			// health bar of one player
	sf::Sprite sprite_hp_bg_one;
	sf::Sprite sprite_hp_two;			// health bar of two player
	sf::Sprite sprite_hp_bg_two;
	sf::Sprite sprite_menu_bg;		// bg menu
	sf::Sprite sprite_end_bg;			// bg end of game

	sf::Sound win_one_audio;				// sound of win of player
	sf::SoundBuffer win_one;
	sf::Sound win_two_audio;				// sound of win of player
	sf::SoundBuffer win_two;
	sf::Sound game_started_audio;		// sound of starting game
	sf::SoundBuffer game_started;
	sf::Sound explosion_audio;			// sound of explosion
	sf::SoundBuffer explosion;
	sf::Music Music_audio;					// into game misic
	sf::Music Music_audio_end;			// end game misic
	sf::Music Music_audio_menu;			// menu misic
};


#endif
