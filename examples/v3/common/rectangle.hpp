#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace zemlyak
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t &pos, double width, double height);
    Rectangle(double x, double y, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
    void printInfo() const override;
    void rotate(double angle) override;

  private:
    point_t centre_;
    double width_;
    double height_;
    double angle_;
  };
}

#endif
