#ifndef DETAILS_HPP
#define DETAILS_HPP

#include <memory>
#include <vector>

#include "point.hpp"
#include "edge.hpp"


using namespace std;


class Details
{
public:
    Details() = default;
    ~Details() = default;

    void add_point(Point pt);
    void add_edge(Edge ed);

    void reform(shared_ptr<Matrix<double>> reform_mtr);

    vector<Point> get_points();
    vector<Edge> get_edges();

private:
    vector<Point> points;
    vector<Edge> edges;
};

#endif
