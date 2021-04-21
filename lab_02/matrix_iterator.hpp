#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP


#include <iostream>
#include <memory>
#include "matrix.hpp"
#include "matrix_data.hpp"
using namespace std;


template <typename T>
class Iterator: public iterator<bidirectional_iterator_tag, T>
{
private:
    size_t self_rows = 0;
    size_t self_columns = 0;
    size_t self_index = 0;
    weak_ptr<MatrixData<T>[]> self_data = nullptr;

public:
    Iterator(const Iterator &it) = default;
    Iterator(const Matrix<T> &matrix, const size_t index = 0): self_data(matrix.self_data), self_rows(matrix.self_rows), self_columns(matrix.self_columns), self_index(index) {}

    bool operator!=(Iterator const &value) const;
    bool operator==(Iterator const &value) const;
    bool operator<(Iterator const &value) const;

    Iterator<T>& operator++();
    Iterator<T> operator++(int);

    Iterator<T>& get_next();

    Iterator<T> &operator+=(const int value);
    Iterator<T> &operator=(const Iterator<T> &it);

    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;

    T& value();
    const T& value() const;

    operator bool() const;
    bool is_end() const;
};


template <typename T>
class ConstIterator: public iterator<bidirectional_iterator_tag, T>
{
private:
   size_t self_rows = 0;
   size_t self_columns = 0;
   size_t self_index = 0;
   weak_ptr<MatrixData<T>[]> self_data = nullptr;

public:
   ConstIterator(const Matrix<T> &matrix, const size_t index = 0): self_data(matrix.self_data), self_rows(matrix.self_rows), self_columns(matrix.self_columns), self_index(index){}
   ConstIterator(const ConstIterator& it) = default;
};


#endif
