#ifndef PARTITION_HPP
#define PARTITION_HPP

#include "composite-shape.hpp"
#include "matrix.hpp"

using shape_ptr = std::shared_ptr<zemlyak::Shape>;
using shape_array = std::unique_ptr<shape_ptr[]>;

namespace zemlyak
{
  Matrix part(const shape_array& arr, size_t size);
  Matrix part(const CompositeShape& composite);
}

#endif
