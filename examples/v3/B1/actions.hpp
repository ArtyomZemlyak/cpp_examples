#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <functional>
#include <iostream>
#include "access-pattern.hpp"

enum class direction_t
{
  ascending,
  descending
};

direction_t getDirection(const char* direction);

template <template <typename Collection> class AccessPattern, typename Collection>
void sort(Collection & collection, direction_t direction)
{
  using value_type = typename Collection::value_type;

  std::function <bool(value_type, value_type)> compare = (direction == direction_t::ascending)
                                                         ? std::function <bool(value_type, value_type)>(std::less<value_type>())
                                                         : std::function <bool(value_type, value_type)>(std::greater<value_type>());

  using Pattern = AccessPattern<Collection>;

  const auto begin = Pattern::begin(collection);
  const auto end = Pattern::end(collection);

  for (auto i = begin; i != end; i++)
  {
    for (auto j = Pattern::next(i); j != end; j++) {
      if (compare(Pattern::getElement(collection, j), Pattern::getElement(collection, i)))
      {
        std::swap(Pattern::getElement(collection, j), Pattern::getElement(collection, i));
      }
    }
  }
}

template <typename Collection>
void print(const Collection & collection)
{
  for (auto iter = collection.begin(); iter != collection.end(); iter++)
  {
    std::cout << *iter << ' ';
  }

  std::cout << '\n';

}

#endif //ACTIONS_HPP
