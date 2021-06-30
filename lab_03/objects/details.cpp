#include "details.hpp"

void Details::add_point(Point pt)
{
    points.push_back(pt);
}

void Details::add_edge(Edge ed)
{
    edges.push_back(ed);
}

std::vector<Point> Details::get_points()
{
    return points;
}

std::vector<Edge> Details::get_edges()
{
    return edges;
}

void Details::reform(std::shared_ptr<Matrix<double>> reform_mtr)
{
    for (auto &point : points)
    {
        point.reform(reform_mtr);
    }
}
