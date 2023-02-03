#ifndef BASE_TYPES_H
#define BASE_TYPES_H
#include <SFML/Graphics.hpp>


	struct point_t
	{
		double x;
		double y;
	};

	struct obj_t
	{
		point_t pos;
		double width;
		double height;
		int angle;
	};

	struct cell_t
	{
		int type;
		point_t pos;
		int health;
		double width;
		double height;
		std::string texture;
	};



#endif
