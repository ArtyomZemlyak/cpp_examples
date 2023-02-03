#include "actions.hpp"
#include <cstring>

direction_t getDirection(const char* direction)
{
  if (std::strcmp(direction, "ascending") == 0)
  {
    return direction_t::ascending;
  }

  if (std::strcmp(direction, "descending") == 0)
  {
    return direction_t::descending;
  }

  throw std::invalid_argument("No such direction");
}
