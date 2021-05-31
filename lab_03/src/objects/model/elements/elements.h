#ifndef ELEMENTS_H
#define ELEMENTS_H


#include <iostream>
#include <vector>
#include "./vertex/vertex.h"
#include "./edge/edge.h"


using namespace std;


class Elements
{
public:
    Elements() = default;
    Elements(vector<Vertex> &verteces, vector<Edge> &edges);
    Elements(Vertex &center, vector<Vertex> &verteces, vector<Edge> &edges);

    const vector<Vertex> &get_verteces() const;
    const vector<Edge> &get_edges() const;
    const Vertex &get_center() const;

    void add_vertex(const Vertex &vertex);
    void add_edge(const Edge &edge);

    void transform(const Vertex &move, const Vertex &scale, const Vertex &turn);

    ~Elements() = default;

private:
    vector<Vertex> verteces;
    vector<Edge> edges;
    Vertex center;
};

#endif
