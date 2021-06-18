#ifndef DETAILS_HPP
#define DETAILS_HPP

#include <memory>
#include <vector>

#include "point.hpp"
#include "edge.hpp"


class Details
{
public:
    Details() = default;
    ~Details() = default;

    void add_point(Point pt);
    void add_edge(Edge ed);

    void reform(std::shared_ptr<Matrix<double>> reform_mtr);

    std::vector<Point> get_points();
    std::vector<Edge> get_edges();

private:
    std::vector<Point> points;
    std::vector<Edge> edges;
};

#endif
