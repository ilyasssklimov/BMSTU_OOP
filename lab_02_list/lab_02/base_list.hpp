#ifndef BASE_MATRIX_HPP
#define BASE_MATRIX_HPP


#include <iostream>


class BaseList
{
protected:
    int size;

public:
    virtual int get_size() const = 0;
    virtual operator bool() const = 0;
    virtual void clear() = 0;

    virtual ~BaseList() = default;
};


#endif
