#ifndef ENFFECTS_H
#define ENFFECTS_H

#include "base-types.h"

class effect
{
public:
	effect(double x, double y, int type_e);
	~effect() = default;

	void draw(sf::RenderWindow &window);
	int getStatus();

private:
	void config();

	point_t pos_;
	int type_;

	int status;

	short int effect_status;
	short int effect_status_max;
	long int time_effect;
	int time_animation;

};


#endif
