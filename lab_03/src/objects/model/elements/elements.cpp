#include "elements.h"


Elements::Elements(vector<Vertex> &verteces, vector<Edge> &edges): verteces(verteces), edges(edges) {};


Elements::Elements(Vertex &center, vector<Vertex> &verteces, vector<Edge> &edges): verteces(verteces), edges(edges), center(center) {};


const vector<Vertex> &Elements::get_verteces() const
{
    return verteces;
}


const vector<Edge> &Elements::get_edges() const
{
    return edges;
}


const Vertex &Elements::get_center() const
{
    return center;
}


void Elements::add_vertex(const Vertex &vertex)
{
    verteces.push_back(vertex);
}


void Elements::add_edge(const Edge &edge)
{
    edges.push_back(edge);
}


void Elements::transform(const Vertex &move, const Vertex &scale, const Vertex &turn)
{
    center.move(move.get_x(), move.get_y(), move.get_z());
    for (auto &vertex: verteces)
    {
        vertex.scale(scale.get_x(), scale.get_y(), scale.get_z());
        vertex.turn(turn.get_x(), turn.get_y(), turn.get_z());
    }

}
