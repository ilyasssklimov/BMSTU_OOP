#ifndef MATRIX_ROW_HPP
#define MATRIX_ROW_HPP


#include <iostream>
#include <memory>
#include "matrix_iterator.hpp"
using namespace std;


template <typename T>
class MatrixData
{
private:
    shared_ptr<T> self_data = nullptr;
    size_t self_size = 0;

public:
    friend Iterator<T>;
    friend ConstIterator<T>;

    MatrixData(): self_data(nullptr), self_size(0) {}
    MatrixData(T *data, const size_t size): self_data(data), self_size(size) {}

    T &operator[](size_t index);
    const T &operator[](size_t index) const;

    /*
    void reset(Type *data, const size_t size);
    void reset();
    Type *getAddr() { return _data.get(); }
    const Type *getAddr() const { return _data.get(); }
    */
};


#endif
