#ifndef BASE_MATRIX_HPP
#define BASE_MATRIX_HPP

#include <iostream>


class BaseMatrix
{
protected:
    size_t self_rows = 0, self_columns = 0;

public:
    BaseMatrix(size_t rows, size_t columns): self_rows(rows), self_columns(columns) {}

    virtual size_t get_rows() const noexcept
    {
        return self_rows;
    }
    virtual size_t get_columns() const noexcept
    {
        return self_columns;
    }
    virtual operator bool() const noexcept
    {
        return self_rows && self_columns;
    }

    virtual ~BaseMatrix() = 0;
};


BaseMatrix::~BaseMatrix() {}


#endif
