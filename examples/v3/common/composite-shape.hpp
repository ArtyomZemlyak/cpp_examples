#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>

#include "shape.hpp"

namespace zemlyak
{
  class CompositeShape: public Shape
  {
  public:
    using shape_ptr = std::shared_ptr<Shape>;
    using shape_array = std::unique_ptr<shape_ptr[]>;

    CompositeShape();
    CompositeShape(const CompositeShape& origin);
    CompositeShape(CompositeShape&& origin);
    ~CompositeShape() = default;

    CompositeShape& operator =(const CompositeShape& rhs);
    CompositeShape& operator =(CompositeShape&& rhs);

    shape_ptr operator [](size_t rhs) const;

    bool operator ==(const CompositeShape& rhs) const;
    bool operator !=(const CompositeShape& rhs) const;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t& pos) override;
    void scale(double factor) override;
    void rotate(double angle) override;
    void printInfo() const override;
    void add(shape_ptr shape);
    void remove(size_t index);
    size_t size() const;
    shape_array list() const;

  private:
    size_t counter_;
    double angle_;
    shape_array shapes_array_;
  };
}

#endif
