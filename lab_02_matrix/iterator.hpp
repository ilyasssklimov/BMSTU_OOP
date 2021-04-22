#ifndef ITERATOR_HPP
#define ITERATOR_HPP


#include "matrix_iterator.hpp"


template <typename T>
bool Iterator<T>::operator!=(Iterator const &value) const
{
    return self_index != value.self_index;
}


template <typename T>
bool Iterator<T>::operator==(Iterator const &value) const
{
    return self_index == value.self_index;
}


template <typename T>
bool Iterator<T>::operator<(Iterator const &value) const
{
    return self_index < value.self_index;
}


template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
    if (self_index < self_rows * self_columns)
        ++self_index;
    return *this;
}


template <typename T>
Iterator<T>& Iterator<T>::operator++(int)
{
    Iterator<T> temp(*this);
    ++temp;
    return temp;
}


template <typename T>
Iterator<T>& Iterator<T>::get_next()
{
    return operator++();
}


template <typename T>
Iterator<T> &Iterator<T>::operator+=(const int value)
{
    self_index += value;
    return *this;
}


template <typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &temp)
{
    self_data = temp.self_data;
    self_index = temp.self_index;
    self_rows = temp.self_rows;
    self_columns = temp.self_columns;

    return *this;
}


template <typename T>
bool Iterator<T>::is_end() const
{
    return self_index == self_rows * self_columns;
}


template <typename T>
Iterator<T>::operator bool() const
{
    return self_data.expired();
}

/*
template <typename T>
T& Iterator<T>::operator*()
{
    SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = _data.lock();
    return data_ptr[_index / _cols][_index % _cols];
}

template <typename T>
T& Iterator<T>::value()  {
    return operator*();
}
*/
#endif
