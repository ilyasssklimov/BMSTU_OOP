#ifndef BASE_LOADER_H
#define BASE_LOADER_H


#include <iostream>
using namespace std;


class BaseLoader
{
    BaseLoader() = default;

    virtual void open(string filename);
    virtual void close() = 0;

    virtual ~BaseLoader() = default;
};

#endif
