#include <stdio.h>
#include <stdlib.h>
#include "figure.h"
#include "edge.h"


void init_edges(edge_t &edges)
{
    edges.array = nullptr;
    edges.size = 0;
}


error read_amount_edges(edge_t &edges, FILE *f)
{
    error rc = OK;

    if ((fscanf(f, "%d", &edges.size)) != 1)
        rc = READ_ERROR;
    else
        if (edges.size < 1)
            rc = EDGE_SIZE_ERROR;

    return rc;
}


error allocate_edges(edge_t &edges)
{
    if (edges.size < 1)
        return EDGE_SIZE_ERROR;

    error rc = OK;

    edges.array = (edge *)malloc(edges.size * sizeof(edge));

    if (!edges.array)
        rc = ALLOCATE_ERROR;

    return rc;
}


error read_edges(edge_t &edges, FILE *f)
{
    error rc = OK;
    edge *array_edge = edges.array;
    int size_edge = edges.size;

    for (int i = 0; i < size_edge && rc == OK; i++)
    {
        if (fscanf(f, "%d%d", &array_edge[i].vertex_start, &array_edge[i].vertex_finish) != 2)
            rc = READ_ERROR;
    }

    return rc;
}


void free_edges(edge_t &edges)
{
    if (edges.array)
        free(edges.array);
}


error get_edges(edge_t &edges, FILE *f)
{
    error rc = OK;

    rc = read_amount_edges(edges, f);
    if (rc != OK)
        return rc;

    rc = allocate_edges(edges);
    if (rc == OK)
    {
        rc = read_edges(edges, f);
        if (rc != OK)
            free_edges(edges);
    }

    return rc;
}


int index_start_from_edge(const edge_t &edges, const int index)
{
    edge cur_edge = edges.array[index];
    return cur_edge.vertex_start;
}


int index_finish_from_edge(const edge_t &edges, const int index)
{
    edge cur_edge = edges.array[index];
    return cur_edge.vertex_finish;
}


/*
edge_t &access_to_edge(figure &figure)
{
    return figure.edges;
}
*/


void write_edge_to_file(const edge_t &edges, const int index, FILE *f)
{
    int index_start = index_start_from_edge(edges, index);
    int index_finish = index_finish_from_edge(edges, index);
    fprintf(f, "%d %d\n", index_start, index_finish);
}
