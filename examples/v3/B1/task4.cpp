#include <vector>
#include "actions.hpp"
#include "tasks.hpp"

void fillRandom(double* array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = (rand() % 21 - 10) / 10.0;
  }
}
void task4(const char* direction, int size)
{
  direction_t dir = getDirection(direction);

  if (size <  0)
  {
    throw std::invalid_argument("Size cannot be negative");
  }

  std::vector <double> double_vector(size);
  fillRandom(&double_vector[0], size);

  print(double_vector);
  sort <AccessBrackets>(double_vector,dir);
  print(double_vector);
}
