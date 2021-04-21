#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>
#include "figure.h"


struct edge
{
    int vertex_start;
    int vertex_finish;
};


struct edge_t
{
    edge *array = nullptr;
    int size = 0;
};


void init_edges(edge_t &edges);

error get_edges(edge_t &edges, FILE *f);
void free_edges(edge_t &edges);

int index_start_from_edge(const edge_t &edges, const int index);
int index_finish_from_edge(const edge_t &edges, const int index);

// edge_t &access_to_edge(figure &figure);
void write_edge_to_file(const edge_t &edges, const int index, FILE *f);

#endif
