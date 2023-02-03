#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

zemlyak::Circle::Circle(const point_t &position, const double radius):
  pos_(position),
  radius_(radius)
{
  if (radius < 0)
  {
    throw std::invalid_argument("The radius value of circle must be non-negative.");
  }
}

zemlyak::Circle::Circle(double x, double y, double radius):
  Circle({x, y}, radius)
{ }

double zemlyak::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void zemlyak::Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void zemlyak::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

zemlyak::rectangle_t zemlyak::Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void zemlyak::Circle::scale(double factor)
{
  if (factor < 0)
  {
    throw std::invalid_argument("The radius value of circle must be non-negative.");
  }
  else
  {
    radius_ *= factor;
  }
}

void zemlyak::Circle::rotate(double)
{
  //the circle does not depend on rotation.
}

void zemlyak::Circle::printInfo() const
{
  zemlyak::rectangle_t FrameRectData = getFrameRect();
  std::cout << "Circle:" << std::endl;
  std::cout << "  coordinates (X; Y): (" << pos_.x;
  std::cout << "; " << pos_.y << ")" << std::endl;
  std::cout << "  area: " << getArea() << std::endl;
  std::cout << "  radius: " << radius_ << std::endl;
  std::cout << "  Frame rectangle width: " << FrameRectData.width;
  std::cout << "; height: " << FrameRectData.height << std::endl;
}
