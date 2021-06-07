#ifndef DETAILS_H
#define DETAILS_H

#include <memory>
#include <vector>

#include "point.h"
#include "edge.h"


using namespace std;


class Elements
{
public:
    Elements() = default;
    ~Elements() = default;

    void add_point(Point pt);
    void add_edge(Edge ed);

    void transform(shared_ptr<Matrix<double>> reform_mtr);

    vector<Point> get_points();
    vector<Edge> get_edges();

private:
    vector<Point> points;
    vector<Edge> edges;
};

#endif // DETAILS_H
