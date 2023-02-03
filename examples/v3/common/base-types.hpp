#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace zemlyak
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };

  bool intersect(const rectangle_t& lhs, const rectangle_t& rhs);
}

#endif
