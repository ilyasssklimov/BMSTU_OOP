#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <memory>
#include "base_matrix.hpp"
#include "matrix_data.hpp"
using namespace std;


template <typename T>
class Matrix: public BaseMatrix
{
private:
    shared_ptr<MatrixData<T>[]> self_data {nullptr};
    shared_ptr<MatrixData<T>[]> self_init_data(size_t rows, size_t columns);

public:
    explicit Matrix(size_t rows = 0, size_t columns = 0);


   Matrix(size_t rows, size_t columns, const T &filler);
   Matrix(size_t rows, size_t columns, T **matrix);
   Matrix(std::initializer_list<initializer_list<T>> init_list);
   explicit Matrix(const Matrix &matrix);
   Matrix(Matrix &&matrix);

   virtual ~Matrix() = default;
};


#endif
