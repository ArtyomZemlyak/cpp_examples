#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  std::cout << "Begin of program A1." << std::endl;

  std::cout << "Creating a circle by coordinates X = 5 and Y = 5 with a radius of 5." << std::endl;
  Circle circle_1 = Circle({5, 5}, 5);

  std::cout << "Obtaining information about the first object" << std::endl;
  Shape *shape_1 = &circle_1;
  shape_1->printInfo();
  std::cout << std::endl;

  std::cout << "Move the first object on X = 5 and Y = 10. Info:" << std::endl;
  shape_1->move(5, 10);
  circle_1.printInfo();
  std::cout << std::endl;

  std::cout << "Setting the new coordinates X = 1 and Y = 1 for the first object. Info:" << std::endl;
  shape_1->move({1, 1});
  shape_1->printInfo();
  std::cout << std::endl;

  std::cout << "Creating a rectangle by coordinates X = 0 and Y = 5 with width = 5 and height = 15." << std::endl;
  Rectangle rectangle_1 = Rectangle({0, 5}, 5, 15);

  std::cout << "Obtaining information about the second object" << std::endl;
  shape_1 = &rectangle_1;
  shape_1->printInfo();
  std::cout << std::endl;

  std::cout << "Move the second object on X = 5 and Y = 0. Info:" << std::endl;
  shape_1->move(5, 0);
  shape_1->printInfo();
  std::cout << std::endl;

  std::cout << "Setting the new coordinates X = 10 and Y = 10  for the second object. Info:" << std::endl;
  shape_1->move({10, 10});
  shape_1->printInfo();
  std::cout << std::endl;

  std::cout << "End of program A1." << std::endl;

  return 0;
}
