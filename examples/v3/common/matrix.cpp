#include "matrix.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

zemlyak::Matrix::Matrix():
  rows_(0),
  columns_(0)
{ }

zemlyak::Matrix::Matrix(const Matrix& source):
  rows_(source.rows_),
  columns_(source.columns_),
  list_(std::make_unique<shape_ptr[]>(source.rows_ * source.columns_))
{
  for (size_t i = 0; i < (rows_ * columns_); i++)
  {
    list_[i] = source.list_[i];
  }
}

zemlyak::Matrix::Matrix(Matrix&& source):
  rows_(source.rows_),
  columns_(source.columns_),
  list_(std::move(source.list_))
{ }

zemlyak::Matrix& zemlyak::Matrix::operator =(const Matrix& rhs)
{
  if (this != &rhs)
  {
    rows_ = rhs.rows_;
    columns_ = rhs.columns_;
    shape_array temp_list(std::make_unique<shape_ptr[]>(rhs.rows_ * rhs.columns_));
    for (size_t i = 0; i < (rows_ * columns_); i++)
    {
      temp_list[i] = rhs.list_[i];
    }
    list_.swap(temp_list);
  }

  return *this;
}

zemlyak::Matrix& zemlyak::Matrix::operator =(Matrix&& rhs)
{
  if (this != &rhs)
  {
    rows_ = rhs.rows_;
    columns_ = rhs.columns_;
    list_ = std::move(rhs.list_);
  }

  return *this;
}

zemlyak::Matrix::shape_array zemlyak::Matrix::operator [](size_t rhs) const
{
  if (rhs >= rows_)
  {
    throw std::out_of_range("Index is out of range");
  }

  shape_array temp_list(std::make_unique<shape_ptr[]>(columns_));
  for (size_t i = 0; i < columns_; i++)
  {
    temp_list[i] = list_[rhs * columns_ + i];
  }

  return temp_list;
}

bool zemlyak::Matrix::operator ==(const Matrix& rhs) const
{
  if ((rows_ != rhs.rows_) || (columns_ != rhs.columns_))
  {
    return false;
  }

  for (size_t i = 0; i < (rows_ * columns_); i++)
  {
    if (list_[i] != rhs.list_[i])
    {
      return false;
    }
  }

  return true;
}

bool zemlyak::Matrix::operator !=(const Matrix& rhs) const
{
  return !(*this == rhs);
}

void zemlyak::Matrix::add(shape_ptr shape, size_t row, size_t column)
{
  size_t temp_rows = (row == rows_) ? (rows_ + 1) : (rows_);
  size_t temp_columns = (column == columns_) ? (columns_ + 1) : (columns_);

  shape_array temp_list(std::make_unique<shape_ptr[]>(temp_rows * temp_columns));

  for (size_t i = 0; i < temp_rows; i++)
  {
    for (size_t j = 0; j < temp_columns; j++)
    {
      if ((i == rows_) || (j == columns_))
      {
        temp_list[i * temp_columns + j] = nullptr;
      }
      else
      {
        temp_list[i * temp_columns + j] = list_[i * columns_ + j];
      }
    }
  }
  temp_list[row * temp_columns + column] = shape;
  list_.swap(temp_list);
  rows_ = temp_rows;
  columns_ = temp_columns;
}

void zemlyak::Matrix::printInfo() const
{
  std::cout << "Matrix size: " << std::endl
            << " -- rows: " << rows_ << std::endl
            << " -- columns: " << columns_ << std::endl;
  for (size_t i = 0; i < rows_; ++i)
  {
    for (size_t j = 0; j < columns_; ++j)
    {
      if (list_[i * columns_ + j] != nullptr)
      {
        std::cout << "layer: " << i + 1
                  << ", column: " << j + 1 << std::endl
                  << "Object information:" << std::endl;
        list_[i * columns_ + j]->printInfo();
        if ((list_[i * columns_ + j + 1] != nullptr) || ((rows_ - i) != 1))
        {
          std::cout << std::endl << "  -- next object --" << std::endl;
        }
      }
    }
  }
}

size_t zemlyak::Matrix::getRows() const
{
  return rows_;
}

size_t zemlyak::Matrix::getColumns() const
{
  return columns_;
}
