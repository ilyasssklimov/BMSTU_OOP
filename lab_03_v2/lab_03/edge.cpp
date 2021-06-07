#include "edge.h"

Edge::Edge()
{

}

Edge::Edge(const long point1, const long point2)
    :point1(point1), point2(point2)
{
}

long Edge::get_first()
{
    return point1;
}

long Edge::get_second()
{
    return point2;
}
