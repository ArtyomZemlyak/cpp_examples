#include <vector>
#include <forward_list>
#include "tasks.hpp"
#include "actions.hpp"

void task1(const char* direction)
{
  const direction_t dir = getDirection(direction);

  std::vector <int> vector_bracket;
  int num = -1;
  while (std::cin && !(std::cin >> num).eof())
  {
    if (std::cin.fail()) {
      throw std::ios_base::failure("Error reading data");
    }
    vector_bracket.push_back(num);
  }

  if (vector_bracket.empty())
  {
    return;
  }

  std::vector <int> vector_at(vector_bracket);
  std::forward_list <int> mailing_list(vector_bracket.begin(), vector_bracket.end());

  sort <AccessBrackets> (vector_bracket, dir);
  print(vector_bracket);

  sort <AccessAt> (vector_at, dir);
  print(vector_at);

  sort <AccessIterator> (mailing_list, dir);
  print(mailing_list);

}
