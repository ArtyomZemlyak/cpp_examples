#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

int main()
{
  std::cout << "Begin of program A3." << std::endl;

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

  std::cout << "Scale the second object on scale factor = 2. Info:" << std::endl;
  shape_1->scale(2);
  shape_1->printInfo();
  std::cout << std::endl;

  zemlyak::CompositeShape::shape_ptr part1 = std::make_shared<zemlyak::Rectangle>(rectangle_1);
  zemlyak::CompositeShape::shape_ptr part2 = std::make_shared<zemlyak::Circle>(circle_1);

  std::cout << "Creating a composite of shapes. Info:" << std::endl;
  zemlyak::CompositeShape shapes;
  shapes.printInfo();
  std::cout << std::endl;

  std::cout << "Adding a rectangle shape to a composite of shapes. Info:" << std::endl;
  shapes.add(part1);
  shapes.printInfo();
  std::cout << std::endl;

  std::cout << "Adding a circle shape to a composite of shapes. Info:" << std::endl;
  shapes.add(part2);
  shapes.printInfo();
  std::cout << std::endl;

  std::cout << "Move shapes on X = 5 and Y = 0. Info:" << std::endl;
  shapes.move(5, 0);
  shapes.printInfo();
  std::cout << std::endl;

  std::cout << "Setting the new coordinates X = 10 and Y = 10 for the shapes. Info:" << std::endl;
  shapes.move({10, 10});
  shapes.printInfo();
  std::cout << std::endl;

  std::cout << "Scale shapes on scale factor = 2. Info:" << std::endl;
  shapes.scale(2);
  shapes.printInfo();
  std::cout << std::endl;

  std::cout << "Removing a circle shape from a composite of shapes. Info:" << std::endl;
  shapes.remove(1);
  shapes.printInfo();
  std::cout << std::endl;

  std::cout << "End of program A3." << std::endl;

  return 0;
}
