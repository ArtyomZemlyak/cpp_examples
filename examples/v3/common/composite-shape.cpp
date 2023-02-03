#include "composite-shape.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <utility>

const double full_circle = 360.0;

zemlyak::CompositeShape::CompositeShape():
  counter_(0),
  angle_(0)
{ }

zemlyak::CompositeShape::CompositeShape(const CompositeShape& origin):
  counter_(origin.counter_),
  angle_(origin.angle_),
  shapes_array_(std::make_unique<shape_ptr[]>(origin.counter_))
{
  for (size_t i = 0; i < counter_; i++)
  {
    shapes_array_[i] = origin.shapes_array_[i];
  }
}

zemlyak::CompositeShape::CompositeShape(CompositeShape&& origin):
  counter_(origin.counter_),
  angle_(origin.angle_),
  shapes_array_(std::move(origin.shapes_array_))
{
  origin.counter_ = 0;
  origin.shapes_array_ = nullptr;
}

zemlyak::CompositeShape& zemlyak::CompositeShape::operator =(const CompositeShape& rhs)
{
  if (this != &rhs)
  {
    counter_ = rhs.counter_;
    angle_ = rhs.angle_;
    shape_array temp_array(std::make_unique<shape_ptr[]>(rhs.counter_));
    for (size_t i = 0; i < counter_; i++)
    {
      temp_array[i] = rhs.shapes_array_[i];
    }
    shapes_array_.swap(temp_array);
  }
  return *this;
}

zemlyak::CompositeShape& zemlyak::CompositeShape::operator =(CompositeShape&& rhs)
{
  if (this != &rhs)
  {
    shapes_array_ = std::move(rhs.shapes_array_);
    angle_ = rhs.angle_;
    counter_ = rhs.counter_;
    rhs.shapes_array_ = nullptr;
    rhs.angle_ = 0;
    rhs.counter_ = 0;
  }
  return *this;
}

zemlyak::CompositeShape::shape_ptr zemlyak::CompositeShape::operator [](size_t rhs) const
{
  if (rhs >= counter_)
  {
    throw std::out_of_range("Index is out of range");
  }

  return shapes_array_[rhs];
}

bool zemlyak::CompositeShape::operator ==(const CompositeShape& rhs) const
{
  if (counter_ != rhs.counter_)
  {
    return false;
  }

  for (size_t i = 0; i < counter_; i++)
  {
    if (shapes_array_[i] != rhs.shapes_array_[i])
    {
      return false;
    }
  }

  return true;
}

bool zemlyak::CompositeShape::operator !=(const CompositeShape& rhs) const
{
  return !(*this == rhs);
}

double zemlyak::CompositeShape::getArea() const
{
  double common_area = 0;
  for (size_t i = 0; i < counter_; i++)
  {
    common_area += shapes_array_[i]->getArea();
  }
  return common_area;
}

zemlyak::rectangle_t zemlyak::CompositeShape::getFrameRect() const
{
  if (counter_ == 0)
  {
    return {{0, 0}, 0, 0};
  }

  rectangle_t temp_frame_rect = shapes_array_[0]->getFrameRect();
  double left = temp_frame_rect.pos.x - temp_frame_rect.width / 2;
  double right = temp_frame_rect.pos.x + temp_frame_rect.width / 2;
  double bottom = temp_frame_rect.pos.y - temp_frame_rect.height / 2;
  double top = temp_frame_rect.pos.y + temp_frame_rect.height / 2;

  for (size_t i = 1; i < counter_; i++)
  {
    temp_frame_rect = shapes_array_[i]->getFrameRect();

    double temp_value = temp_frame_rect.pos.x - temp_frame_rect.width / 2;
    left = std::min(temp_value, left);

    temp_value = temp_frame_rect.pos.x + temp_frame_rect.width / 2;
    right = std::max(temp_value, right);

    temp_value = temp_frame_rect.pos.y - temp_frame_rect.height / 2;
    bottom = std::min(temp_value, bottom);

    temp_value = temp_frame_rect.pos.y + temp_frame_rect.height / 2;
    top = std::max(temp_value, top);
  }

  return {{(left + right) / 2, (bottom + top) / 2}, right - left, top - bottom};
}

void zemlyak::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < counter_; i++)
  {
    shapes_array_[i]->move(dx, dy);
  }
}

void zemlyak::CompositeShape::move(const point_t& pos)
{
  const double dx = pos.x - getFrameRect().pos.x;
  const double dy = pos.y - getFrameRect().pos.y;
  move(dx, dy);
}

void zemlyak::CompositeShape::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Value of scale factor must be non-negative.");
  }

  const point_t pos = getFrameRect().pos;
  for (size_t i = 0; i < counter_; i++)
  {
    const point_t pos_i = shapes_array_[i]->getFrameRect().pos;
    const double dx = pos_i.x - pos.x;
    const double dy = pos_i.y - pos.y;
    shapes_array_[i]->move({pos.x + dx * factor, pos.y + dy * factor});
    shapes_array_[i]->scale(factor);
  }
}

void zemlyak::CompositeShape::rotate(double angle)
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

  const point_t centre = getFrameRect().pos;
  const double angle_cons = angle * M_PI / 180;
  const double sine = sin(angle_cons);
  const double cosine = cos(angle_cons);

  for (size_t i = 0; i < counter_; i++)
  {
    const point_t pos_i = shapes_array_[i]->getFrameRect().pos;
    const double oldX = pos_i.x - centre.x;
    const double oldY = pos_i.y - centre.y;

    const double newX = oldX * fabs(cosine) - oldY * fabs(sine);
    const double newY = oldX * fabs(sine) + oldY * fabs(cosine);

    shapes_array_[i]->move({centre.x + newX, centre.y + newY});
    shapes_array_[i]->rotate(angle);
  }
}

void zemlyak::CompositeShape::printInfo() const
{
  std::cout << "CompositeShape:" << std::endl;
  std::cout << "  coordinates (X; Y): (" << getFrameRect().pos.x;
  std::cout << "; " << getFrameRect().pos.y << ")" << std::endl;
  std::cout << "  area: " << getArea() << std::endl;
  std::cout << "  frame rectangle width: " << getFrameRect().width;
  std::cout << "; height: " << getFrameRect().height << std::endl;
  std::cout << "  angle: " << angle_ << std::endl;
  std::cout << "  amount of shapes: " << counter_ << std::endl;
  std::cout << "Shapes:" << std::endl;
  for (size_t i = 0; i < counter_; i++)
  {
    std::cout << i + 1 << ":" << std::endl;
    shapes_array_[i]->printInfo();
  }
}

void zemlyak::CompositeShape::add(shape_ptr shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Pointer of added shape cannot be null.");
  }

  shape_array temp_array(std::make_unique<shape_ptr[]>(counter_ + 1));
  for (size_t i = 0; i < counter_; i++)
  {
    temp_array[i] = shapes_array_[i];
  }
  temp_array[counter_] = shape;
  counter_++;
  shapes_array_.swap(temp_array);
}

void zemlyak::CompositeShape::remove(size_t index)
{
  if (index >= counter_)
  {
    throw std::out_of_range("The index is beyond the working limits.");
  }

  for (size_t i = index; i < counter_ - 1; i++)
  {
    shapes_array_[i] = shapes_array_[i + 1];
  }
  shapes_array_[counter_ - 1] = nullptr;
  counter_--;
}

size_t zemlyak::CompositeShape::size() const
{
  return counter_;
}

zemlyak::CompositeShape::shape_array zemlyak::CompositeShape::list() const
{
  shape_array temp_array(std::make_unique<shape_ptr[]>(counter_));
  for (size_t i = 0; i < counter_; i++)
  {
    temp_array[i] = shapes_array_[i];
  }

  return temp_array;
}
