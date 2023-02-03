#include "partition.hpp"

zemlyak::Matrix zemlyak::part(const shape_array& arr, size_t size)
{
  Matrix matrix;

  for (size_t i = 0; i < size; i++)
  {
    size_t right_row = 0;
    size_t right_column = 0;
    for (size_t j = 0; j < matrix.getRows(); j++)
    {
      for (size_t k = 0; k < matrix.getColumns(); k++)
      {
        if (matrix[j][k] == nullptr)
        {
          right_row = j;
          right_column = k;
          break;
        }

        if (intersect(arr[i]->getFrameRect(), matrix[j][k]->getFrameRect()))
        {
          right_row = j + 1;
          right_column = 0;
          break;
        }
        else
        {
          right_row = j;
          right_column = k + 1;
        }
      }

      if (right_row == j) //if the right row is found
      {
        break;
      }
    }

    matrix.add(arr[i], right_row, right_column);
  }

  return matrix;
}

zemlyak::Matrix zemlyak::part(const CompositeShape& composite)
{
  return part(composite.list(), composite.size());
}
