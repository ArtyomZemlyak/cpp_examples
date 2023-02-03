#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  std::cout << "Begin of program A2." << std::endl;

  std::cout << "Creating a circle by coordinates X = 5 and Y = 5 with a radius of 10." << std::endl;
  zemlyak::Circle circle_1({5, 5}, 10);

  std::cout << "Obtaining information about the first object." << std::endl;
  zemlyak::Shape *shape_1 = &circle_1;
  shape_1->printInfo();
  std::cout << std::endl;

  std::cout << "Scale the first object on scale factor = 0.5 . Info:" << std::endl;
  shape_1->scale(0.5);
  circle_1.printInfo();
  std::cout << std::endl;

  std::cout << "Creating a rectangle by coordinates X = 0 and Y = 5 with width = 1 and height = 5." << std::endl;
  zemlyak::Rectangle rectangle_1({0, 5}, 1, 5);

  std::cout << "Obtaining information about the second object." << std::endl;
  shape_1 = &rectangle_1;
  shape_1->printInfo();
  std::cout << std::endl;

  std::cout << "Scale the second object on scale factor = 2 . Info:" << std::endl;
  shape_1->scale(2);
  shape_1->printInfo();
  std::cout << std::endl;

  std::cout << "End of program A2." << std::endl;

  return 0;
}
