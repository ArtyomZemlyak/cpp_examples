#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <string>

#include "config.h"
#include "game.h"

void game::config()
{
	srand(time(NULL));

	health_one_ = BASE_HP;
	health_two_ = BASE_HP;

	game_started.loadFromFile(SOUND_GAME_STARTED);
	game_started_audio.setBuffer(game_started);

	Music_audio.openFromFile(MUSIC_GAME);
	Music_audio.setLoop(1);

	Music_audio_end.openFromFile(MUSIC_GAME_WIN);
	Music_audio_end.setVolume(float(20));

	Music_audio_menu.openFromFile(MUSIC_MENU);
	Music_audio_menu.setVolume(float(20));

	win_one.loadFromFile(SOUND_PLAYER_ONE_WIN);
	win_one_audio.setBuffer(win_one);
	win_two.loadFromFile(SOUND_PLAYER_TWO_WIN);
	win_two_audio.setBuffer(win_two);

	float x_one = 301.0;
	float y_one = 513.0;
	texture_hp_one.loadFromFile(HP_TEXTURE);
	sprite_hp_one.setTexture(texture_hp_one);
	sprite_hp_one.setPosition(x_one + 1, y_one + 1);
	texture_hp_bg_one.loadFromFile(HP_TEXTURE_BG);
	sprite_hp_bg_one.setTexture(texture_hp_bg_one);
	sprite_hp_bg_one.setPosition(x_one, y_one);

	float x_two = 301.0;
	float y_two = 17.0;
	texture_hp_two.loadFromFile(HP_TEXTURE);
	sprite_hp_two.setTexture(texture_hp_two);
	sprite_hp_two.setPosition(x_two + 1, y_two + 1);
	texture_hp_bg_two.loadFromFile(HP_TEXTURE_BG);
	sprite_hp_bg_two.setTexture(texture_hp_bg_two);
	sprite_hp_bg_two.setPosition(x_two, y_two);

	texture_menu_bg.loadFromFile(MENU_BG);
	sprite_menu_bg.setTexture(texture_menu_bg);

	texture_end_bg.loadFromFile(GAME_END_BG);
	sprite_end_bg.setTexture(texture_end_bg);

	type_one_ = -1;
	type_two_ = -1;
}

game::game(int status) :
	status_(status)
{
	config();
	Music_audio_menu.play();
}

void game::Hit(int player)
{
	if (player == 0)
	{
		if (health_one_ > 24) health_one_ -= 25;
		else health_one_ = 0;
	}
	if (player == 1)
	{
		if (health_two_ > 24) health_two_ -= 25;
		else health_two_ = 0;
	}

	if (health_one_ == 0)
	{
		status_ = 2;

		win_two_audio.play();
		
		Music_audio.stop();
		Music_audio_end.play();
	}
	if (health_two_ == 0)
	{
		status_ = 2;

		win_one_audio.play();

		Music_audio.stop();
		Music_audio_end.play();
	}
}

void game::draw(sf::RenderWindow &window)
{
	if (status_ == -2)
	{
		window.draw(sprite_menu_bg);

		sf::Font font;
		font.loadFromFile(FONT_GAME);
		sf::Text text("TANKS", font, 70);
		sf::Color color_text(0, 250, 154, 255);
		text.setFillColor(color_text);
		text.setPosition(float(290), float(100));
		window.draw(text);
		sf::Text text2("press ENTER to CHOICE TYPE OF TANK", font, 20);
		text2.setPosition(float(225), float(230));
		window.draw(text2);
	}
	if (status_ == -1)
	{
		window.draw(sprite_menu_bg);

		sprite_end_bg.setPosition(float(0), float(50));
		window.draw(sprite_end_bg);

		sf::Font font;
		font.loadFromFile(FONT_GAME);
		sf::Text text("TANKS", font, 70);
		sf::Color color_text(0, 250, 154, 255);
		text.setFillColor(color_text);
		text.setPosition(float(290), float(100));
		window.draw(text);

		sf::Color color_text_one(0, 250, 154, 255);
		sf::Color color_text_two(30, 144, 255, 255);

		sf::Text text2("press 1 or 2 or 3 to PLAYER ONE", font, 20);
		text2.setPosition(float(50), float(230));
		window.draw(text2);
		sf::Text text5("BALANCE", font, 20);
		text5.setPosition(float(50), float(260));
		window.draw(text5);
		sf::Text text6("HEAVY", font, 20);
		text6.setPosition(float(150), float(260));
		window.draw(text6);
		sf::Text text7("LIGHT", font, 20);
		text7.setPosition(float(230), float(260));
		window.draw(text7);
		if (type_one_ == 0)
		{
			sf::Text text8("BALANCE", font, 20);
			text8.setFillColor(color_text_one);
			text8.setPosition(float(50), float(260));
			window.draw(text8);
		}
		if (type_one_ == 1)
		{
			sf::Text text8("HEAVY", font, 20);
			text8.setFillColor(color_text_one);
			text8.setPosition(float(150), float(260));
			window.draw(text8);
		}
		if (type_one_ == 2)
		{
			sf::Text text8("LIGHT", font, 20);
			text8.setFillColor(color_text_one);
			text8.setPosition(float(230), float(260));
			window.draw(text8);
		}

		sf::Text text3("press NUM1 or NUM2 or NUM3 to PLAYER TWO", font, 20);
		text3.setPosition(float(50), float(310));
		window.draw(text3);
		sf::Text text9("BALANCE", font, 20);
		text9.setPosition(float(50), float(340));
		window.draw(text9);
		sf::Text text10("HEAVY", font, 20);
		text10.setPosition(float(150), float(340));
		window.draw(text10);
		sf::Text text11("LIGHT", font, 20);
		text11.setPosition(float(230), float(340));
		window.draw(text11);
		if (type_two_ == 0)
		{
			sf::Text text12("BALANCE", font, 20);
			text12.setFillColor(color_text_two);
			text12.setPosition(float(50), float(340));
			window.draw(text12);
		}
		if (type_two_ == 1)
		{
			sf::Text text12("HEAVY", font, 20);
			text12.setFillColor(color_text_two);
			text12.setPosition(float(150), float(340));
			window.draw(text12);
		}
		if (type_two_ == 2)
		{
			sf::Text text12("LIGHT", font, 20);
			text12.setFillColor(color_text_two);
			text12.setPosition(float(230), float(340));
			window.draw(text12);
		}
		if ((type_one_ != (-1)) && (type_two_ != (-1)))
		{
			sf::Text text4("press ENTER to START", font, 20);
			text4.setPosition(float(300), float(380));
			window.draw(text4);
		}
	}

	if (status_ > 0)
	{
		sprite_hp_one.setScale(float(health_one_) / float(100), float(1));
		window.draw(sprite_hp_bg_one);
		window.draw(sprite_hp_one);
		sprite_hp_two.setScale(float(health_two_) / float(100), float(1));
		window.draw(sprite_hp_bg_two);
		window.draw(sprite_hp_two);
		if (status_ > 1)
		{
			sprite_end_bg.setPosition(float(0), float(0));
			window.draw(sprite_end_bg);
		}
	}
}

int game::status(int health_one, int health_two)
{
	if (status_ == -2)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) 
		{
			status_ = -1;
		}
	}
	if (status_ == -1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))	type_one_ = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))	type_one_ = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))	type_one_ = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))	type_two_ = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	type_two_ = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))	type_two_ = 2;
		/*if ((type_one_ != (-1)) && (type_two_ != (-1))) status_ = 0;
	}
	if (status_ == 0)
	{*/
		if ((type_one_ != (-1)) && (type_two_ != (-1)))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			game_started_audio.play();
			Music_audio_menu.stop();
			Music_audio.play();
			status_ = 1;
		}
	}
	if ((health_one_ == 0) || (health_one == 0))
	{
		health_one_ = 0;
		if (status_ == 1)
		{
			win_two_audio.play();
			Music_audio.stop();
			Music_audio_end.play();
			status_ = 2;
		}
		return 3;
	}
	if ((health_two_ == 0) || (health_two == 0))
	{
		health_two_ = 0;
		if (status_ == 1)
		{
			win_one_audio.play();
			Music_audio.stop();
			Music_audio_end.play();
			status_ = 2;
		}
		return 2;
	}
	return status_;
}

void game::text_win(int status, sf::RenderWindow &window)
{
	if (status == 2)
	{
		sf::Font font;
		font.loadFromFile(FONT_GAME);
		sf::Text text("PLAYER ONE WIN", font, 50);
		sf::Color color_text(0, 250, 154, 255);
		text.setFillColor(color_text);
		text.setPosition(float(205), float(200));
		window.draw(text);
		sf::Text text2("press ENTER to RESTART", font, 20);
		text2.setPosition(float(300), float(280));
		window.draw(text2);
	}
	if (status == 3)
	{
		sf::Font font;
		font.loadFromFile(FONT_GAME);
		sf::Text text("PLAYER TWO WIN", font, 50);
		sf::Color color_text(30, 144, 255, 255);
		text.setFillColor(color_text);
		text.setPosition(float(205), float(200));
		window.draw(text);
		sf::Text text2("press ENTER to RESTART", font, 20);
		text2.setPosition(float(300), float(280));
		window.draw(text2);
	}
}

int game::getType(int player)
{
	if (player == 0)	return type_one_;
	if (player == 1)	return type_two_;
}

void game::setStatus(int status_set)
{
	int buff_status = status_;
	status_ = status_set;
	if (buff_status == 0 && status_ == 0)
	{
		game_started_audio.play();
		Music_audio_menu.stop();
		Music_audio.play();
	}
}
