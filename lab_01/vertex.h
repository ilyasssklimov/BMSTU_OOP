#ifndef VERTEX_H
#define VERTEX_H

#include <stdio.h>
#include "figure.h"
#include "action.h"


struct vertex
{
    double x;
    double y;
    double z;
};


struct vertex_t
{
    vertex *array = nullptr;
    int size = 0;
};


void init_verteces(vertex_t &verteces);

error get_verteces(vertex_t &verteces, FILE *f);
void free_verteces(vertex_t &verteces);

// vertex &vertex_by_index(vertex_t &verteces, int index);
// vertex_t &access_to_vertex(struct figure &figure);

void add_to_vertex(vertex &vertex, const triplet &coeffs);
void mult_vertex(vertex &vertex, const triplet &coeffs);
void turn_vertex(vertex &vertex, const triplet &coeffs);

void write_vertex_to_file(FILE *f, const vertex &vertex);

#endif
