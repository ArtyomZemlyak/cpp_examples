#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

Circle::Circle(const point_t &position, const double radius):
  pos_(position),
  radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void Circle::printInfo() const
{
  rectangle_t FrameRectData = getFrameRect();
  std::cout << "Circle:" << std::endl;
  std::cout << "  coordinates (X; Y): (" << pos_.x;
  std::cout << "; " << pos_.y << ")" << std::endl;
  std::cout << "  area: " << getArea() << std::endl;
  std::cout << "  radius: " << radius_ << std::endl;
  std::cout << "  Frame rectangle width: " << FrameRectData.width;
  std::cout << "; height: " << FrameRectData.height << std::endl;
}
