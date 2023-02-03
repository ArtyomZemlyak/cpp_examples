#ifndef ACCESS_PATTERN_HPP
#define ACCESS_PATTERN_HPP
#include <iterator>

template <typename Collection>
struct AccessBrackets
{

  static typename Collection::reference getElement(Collection & collection, size_t index)
  {
    return collection[index];
  }

  static size_t begin(const Collection &)
  {
    return 0;
  }

  static size_t end(const Collection & collection)
  {
    return collection.size();
  }

  static size_t next(size_t index)
  {
    return index + 1;
  }

};

template <typename Collection>
struct AccessAt
{

  static typename Collection::reference getElement(Collection & collection, size_t index)
  {
    return collection.at(index);
  }

  static size_t begin(const Collection &)
  {
    return 0;
  }

  static size_t end(const Collection & collection)
  {
    return collection.size();
  }

  static size_t next(size_t index)
  {
    return index + 1;
  }

};

template <typename Collection>
struct AccessIterator
{

  static typename Collection::reference getElement(Collection &,typename Collection::iterator iter)
  {
    return *iter;
  }

  static typename Collection::iterator begin(Collection & collection)
  {
    return collection.begin();
  }

  static typename Collection::iterator end(Collection & collection)
  {
    return collection.end();
  }

  static typename Collection::iterator next(typename Collection::iterator iter)
  {
    return iter++;
  }

};

#endif //ACCESS_PATTERN_HPP
