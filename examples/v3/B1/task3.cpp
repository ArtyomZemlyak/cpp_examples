#include <vector>
#include "actions.hpp"
#include "tasks.hpp"


void task3()
{
  std::vector <int> int_vector;

  int num = -1;
  while (std::cin >> num)
  {
    if (num == 0)
    {
      break;
    }
    else
    {
      int_vector.push_back(num);
    }
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::ios_base::failure("Error reading from std::cin");
  }

  if (int_vector.empty())
  {
    return;
  }

  if (num != 0)
  {
    throw std::runtime_error("Invalid end of line symbol, 0 is necessary");
  }

  switch (int_vector.back())
  {
    case 1:
      for (auto i = int_vector.begin(); i != int_vector.end();)
      {
        if (*i % 2 == 0)
        {
          i = int_vector.erase(i);
        }
        else
        {
          i++;
        }
      }
      break;

    case 2:
      for (auto i = int_vector.begin(); i != int_vector.end();)
      {
        if (*i % 3 == 0)
        {
          i = int_vector.insert(++i, 3, 1);
        }
        else
        {
          i++;
        }
      }
      break;

    default:
      break;
  }

  print(int_vector);
}
