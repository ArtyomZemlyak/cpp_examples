#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"
#include "partition.hpp"


int main()
{
  std::cout << " -- Creating shapes" << std::endl;
  zemlyak::Rectangle rectangle1(9, 4, 1.5, 4);
  rectangle1.printInfo();
  zemlyak::Rectangle rectangle2(11, 3, 7, 6);
  rectangle2.printInfo();
  zemlyak::Circle circle1(17, 7.33, 12);
  circle1.printInfo();
  zemlyak::Circle circle2(0, 0, 1);
  circle2.printInfo();
  zemlyak::Rectangle rectangle3(2, 2, 1, 1);
  circle2.printInfo();
  std::cout << "" << std::endl;

  std::cout << " -- Rotating the first rectangle shape by 90 degrees" << std::endl;
  rectangle1.rotate(90);
  rectangle1.printInfo();
  std::cout << "" << std::endl;

  zemlyak::CompositeShape::shape_ptr part1 = std::make_shared<zemlyak::Rectangle>(rectangle1);
  zemlyak::CompositeShape::shape_ptr part2 = std::make_shared<zemlyak::Rectangle>(rectangle2);
  zemlyak::CompositeShape::shape_ptr part3 = std::make_shared<zemlyak::Circle>(circle1);
  zemlyak::CompositeShape::shape_ptr part4 = std::make_shared<zemlyak::Circle>(circle2);
  zemlyak::CompositeShape::shape_ptr part5 = std::make_shared<zemlyak::Rectangle>(rectangle3);

  std::cout << " -- Creating composite of shapes" << std::endl;
  zemlyak::CompositeShape composite;
  composite.add(part1);
  composite.add(part2);
  composite.add(part3);
  composite.add(part4);
  composite.add(part5);
  composite.printInfo();
  std::cout << "" << std::endl;

  std::cout << " -- Rotating the composite shape by 90 degrees" << std::endl;
  composite.rotate(90);
  composite.printInfo();
  std::cout << "" << std::endl;

  std::cout << " -- Creating matrix from composite" << std::endl;
  zemlyak::Matrix mtx = zemlyak::part(composite);
  mtx.printInfo();
  std::cout << "" << std::endl;
  std::cout << " -- Rotating the composite shape by 90 degrees" << std::endl;
  composite.rotate(90);
  mtx.printInfo();
  std::cout << "" << std::endl;

  return 0;
}
