#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace zemlyak
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &pos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double factor) = 0;
    virtual void printInfo() const = 0;
    virtual void rotate(double angle) = 0;
  };
}

#endif
