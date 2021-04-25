#ifndef BASE_MATRIX_HPP
#define BASE_MATRIX_HPP


#include <iostream>


class BaseList
{
protected:
    size_t size;

public:
    virtual size_t get_size() const noexcept = 0;
    virtual operator bool() const noexcept = 0;
    virtual void clear() noexcept = 0;

    virtual ~BaseList() = 0;
};


BaseList::~BaseList() {}


#endif
