#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace zemlyak
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &pos, double radius);
    Circle(double x, double y, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
    void rotate(double) override;
    void printInfo() const override;

  private:
    point_t pos_;
    double radius_;
  };
}

#endif
