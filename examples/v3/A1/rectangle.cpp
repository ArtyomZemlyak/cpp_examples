#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &position, const double width, const double height):
  rect_({position, width, height})
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
   return rect_;
}

void Rectangle::move(const point_t &pos)
{
  rect_.pos = pos;
}

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::printInfo() const
{
  rectangle_t FrameRectData = getFrameRect();
  std::cout << "Rectangle:" << std::endl;
  std::cout << "  coordinates (X; Y): (" << rect_.pos.x;
  std::cout << "; " << rect_.pos.y << ")" << std::endl;
  std::cout << "  area: " << getArea() << std::endl;
  std::cout << "  Frame rectangle width: " << FrameRectData.width;
  std::cout << "; height: " << FrameRectData.height << std::endl;
}
