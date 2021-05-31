#include "edge.h"


Edge::Edge(const size_t index_1, const size_t index_2): index_start(index_1), index_finish(index_2) {};


size_t Edge::get_start() const
{
    return index_start;
}


size_t Edge::get_finish() const
{
    return index_finish;
}


void Edge::set_start(size_t index)
{
    index_start = index;
}


void Edge::set_finish(size_t index)
{
    index_finish = index;
}
