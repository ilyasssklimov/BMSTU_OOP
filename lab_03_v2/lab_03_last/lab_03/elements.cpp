#include "elements.h"


void Elements::add_point(point pt)
{
    points.push_back(pt);
}


void Elements::add_edge(edge ed)
{
    edges.push_back(ed);
}


vector<Point> Elements::get_points()
{
    return points;
}


vector<Edge> Elements::get_edges()
{
    return edges;
}


void Elements::transform(shared_ptr<Matrix<double>> transform_matrix)
{
    for (auto &point : points)
    {
        point.transform(transform_matrix);
    }
}
