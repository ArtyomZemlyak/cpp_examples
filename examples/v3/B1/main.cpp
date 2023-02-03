#include <iostream>
#include <ctime>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  if ((argc <= 1) || (argc > 4))
  {
    std::cerr << "Invalid number of arguments";
    return 1;
  }

  try
  {
    const int task = std::stoi(argv[1]);

    switch(task)
    {
      case 1:
      {
        if (argc != 3)
        {
          std::cerr << "Invalid number of arguments";
          return 1;
        }
        task1(argv[2]);
        break;
      }

      case 2:
      {
        if (argc != 3)
        {
          std::cerr << "Invalid number of arguments";
          return 1;
        }
        task2(argv[2]);
        break;
      }

      case 3:
      {
        if (argc != 2)
        {
          std::cerr << "Invalid number of arguments";
          return 1;
        }
        task3();
        break;
      }

      case 4:
      {
        if (argc != 4)
        {
          std::cerr << "Invalid number of arguments";
          return 1;
        }
        srand(time(nullptr));
        task4(argv[2], std::stoi(argv[3]));
        break;
      }

      default:
      {
        std::cerr << "Invalid task number";
        return 1;
      }
    }

  }
  catch (const std::exception & e)
  {
    std::cerr << "error: " << e.what() << std::endl;
    return 2;
  }

  return 0;
}
