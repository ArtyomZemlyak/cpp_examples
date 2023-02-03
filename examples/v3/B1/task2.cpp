#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include "tasks.hpp"

const size_t init_size = 256;

void task2(const char* file_name)
{
  std::ifstream input_file(file_name);

  if (!input_file)
  {
    throw std::ios_base::failure("Error opening file");
  }

  using char_array = std::unique_ptr <char[], decltype(free)*>;
  char_array ch_arr(static_cast <char*>(malloc(init_size)), &free);

  if (!ch_arr)
  {
    throw std::runtime_error("Error allocating memory");
  }

  size_t size = init_size;
  size_t count_data = 0;

  while (!input_file.eof())
  {
    input_file.read(&ch_arr[count_data], init_size);
    count_data += input_file.gcount();

    if (input_file.gcount() == init_size)
    {
      size += init_size;
      char_array tmp_array(static_cast <char*> (realloc(ch_arr.get(), size)), &free);

      if (!tmp_array)
      {
        throw std::runtime_error("Error reallocating memory");
      }

      ch_arr.release();
      std::swap(ch_arr, tmp_array);
    }

    if (input_file.fail() && !input_file.eof())
    {
      throw std::runtime_error("Error reading data");
    }
  }

  std::vector <char> (&ch_arr[0], &ch_arr[count_data]);

  for (size_t i = 0; i < count_data; i++)
  {
    std::cout << ch_arr[i];
  }
}
