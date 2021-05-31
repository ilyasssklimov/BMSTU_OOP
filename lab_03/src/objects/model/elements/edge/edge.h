#ifndef EDGE_H
#define EDGE_H


#include <iostream>
using namespace std;


class Edge
{
public:
    Edge() = default;
    Edge(const size_t index_1, const size_t index_2);

    size_t get_start() const;
    size_t get_finish() const;

    void set_start(size_t index);
    void set_finish(size_t index);

    ~Edge() = default;

private:
    size_t index_start, index_finish;
};

#endif
