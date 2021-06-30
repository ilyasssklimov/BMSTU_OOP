#include "edge.hpp"

Edge::Edge() {}


Edge::Edge(const int point1, const int point2): point1(point1), point2(point2) {}


int Edge::get_first()
{
    return point1;
}


int Edge::get_second()
{
    return point2;
}
