#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <memory>

#include "shape.hpp"

namespace zemlyak
{
  class Matrix
  {
  public:
    using shape_ptr = std::shared_ptr<Shape>;
    using shape_array = std::unique_ptr<shape_ptr[]>;

    Matrix();
    Matrix(const Matrix& source);
    Matrix(Matrix&& source);
    ~Matrix() = default;

    Matrix& operator =(const Matrix& rhs);
    Matrix& operator =(Matrix&& rhs);

    shape_array operator [](size_t rhs) const;
    bool operator ==(const Matrix& rhs) const;
    bool operator !=(const Matrix& rhs) const;

    void add(shape_ptr shape, size_t row, size_t column);
    void printInfo() const;
    size_t getRows() const;
    size_t getColumns() const;

  private:
    size_t rows_;
    size_t columns_;
    shape_array list_;
  };
}

#endif
