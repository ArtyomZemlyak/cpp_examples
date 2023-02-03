#include "rectangle.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

const double full_circle = 360.0;

zemlyak::Rectangle::Rectangle(const point_t &pos, double width, double height):
  centre_(pos),
  width_(width),
  height_(height),
  angle_(0)
{
  if (width < 0)
  {
    throw std::invalid_argument("The width value of rectangle must be non-negative.");
  }
  if (height < 0)
  {
    throw std::invalid_argument("The height value of rectangle must be non-negative.");
  }
}

zemlyak::Rectangle::Rectangle(double x, double y, double width, double height):
  Rectangle({x, y}, width, height)
{ }

double zemlyak::Rectangle::getArea() const
{
  return width_ * height_;
}

zemlyak::rectangle_t zemlyak::Rectangle::getFrameRect() const
{
  const double angle_cons = angle_ * M_PI / 180;
  const double sine = sin(angle_cons);
  const double cosine = cos(angle_cons);
  const double width = height_ * fabs(sine) + width_ * fabs(cosine);
  const double height = height_ * fabs(cosine) + width_ * fabs(sine);
  return {centre_, width, height};
}

void zemlyak::Rectangle::move(const point_t &pos)
{
  centre_ = pos;
}

void zemlyak::Rectangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void zemlyak::Rectangle::scale(double factor)
{
  if (factor < 0)
  {
    throw std::invalid_argument("The value of the parties of rectangle must be non-negative.");
  }
  else
  {
    width_ *= factor;
    height_ *= factor;
  }
}

void zemlyak::Rectangle::rotate(double angle)
{
  angle_ += angle;
  if (angle_ < 0)
  {
    angle_ = full_circle + fmod(angle_, full_circle);
  }
  else
  {
    angle_ = fmod(angle_, full_circle);
  }
}

void zemlyak::Rectangle::printInfo() const
{
  zemlyak::rectangle_t FrameRectData = getFrameRect();
  std::cout << "Rectangle:" << std::endl;
  std::cout << "  coordinates (X; Y): (" << centre_.x;
  std::cout << "; " << centre_.y << ")" << std::endl;
  std::cout << "  area: " << getArea() << std::endl;
  std::cout << "  Frame rectangle width: " << FrameRectData.width;
  std::cout << "; height: " << FrameRectData.height << std::endl;
  std::cout << "  angle: " << angle_ << std::endl;
}
