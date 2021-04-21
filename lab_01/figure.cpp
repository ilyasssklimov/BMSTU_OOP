#include <stdio.h>
#include <math.h>
#include <string.h>
#include "figure.h"


void change_center(center_figure &center, const triplet &data)
{
    center.x += data.x;
    center.y += data.y;
    center.z += data.z;
}


figure &init_figure(void)
{
    static figure figure;

    figure.center = { 0., 0., 0. };
    init_edges(figure.edges);
    init_verteces(figure.verteces);

    return figure;
}


error is_figure_init(const figure &figure)
{
    vertex_t verteces = figure.verteces;
    edge_t edges = figure.edges;

    if (verteces.array && edges.array)
        return OK;
    else
        return INIT_ERROR;
}

void free_figure(figure &figure)
{
    free_verteces(figure.verteces);
    free_edges(figure.edges);
}


error create_figure(figure &figure, const char *filename)
{
    if (!strcmp(filename, ""))
        return EMPTY_NAME_ERROR;

    FILE *f = fopen(filename, "r");
    if (!f)
        return FILE_ERROR;


    error rc = OK;
    struct figure tmp_figure = init_figure();

    rc = get_verteces(tmp_figure.verteces, f);
    if (rc == OK)
    {
        rc = get_edges(tmp_figure.edges, f);
        if (rc != OK)
            free_verteces(tmp_figure.verteces);
    }
    fclose(f);

    if (rc == OK)
    {
        if (!is_figure_init(figure))
            free_figure(figure);

        figure.edges = tmp_figure.edges;
        figure.verteces = tmp_figure.verteces;
        figure.center = tmp_figure.center;
    }
    return rc;
}


error carryover_figure(figure &figure, const triplet &coeffs) // const double dx, const double dy, const double dz, )
{
    if (is_figure_init(figure))
        return INIT_ERROR;

    // vertex_t &verteces = access_to_vertex(figure);
    vertex_t verteces = figure.verteces;

    change_center(figure.center, coeffs);

    for (int i = 0; i < verteces.size; i++)
        add_to_vertex(verteces.array[i], coeffs);

    return OK;
}


error scale_figure(figure &figure, const triplet &coeffs) // const double kx, const double ky, const double kz)
{
    if (is_figure_init(figure))
        return INIT_ERROR;

    // vertex_t &verteces = access_to_vertex(figure);
    vertex_t verteces = figure.verteces;
    center_figure center = figure.center;

    triplet to_init_center = {
        .x = -center.x,
        .y = -center.y,
        .z = -center.z
    };
    triplet to_cur_center = {
        .x = center.x,
        .y = center.y,
        .z = center.z
    };

    for (int i = 0; i < verteces.size; i++)
    {
        add_to_vertex(verteces.array[i], to_init_center);
        mult_vertex(verteces.array[i], coeffs);
        add_to_vertex(verteces.array[i], to_cur_center);
    }
    return OK;
}


error turn_figure(figure &figure, const triplet &coeffs) // const double ox, const double oy, const double oz)
{
    if (is_figure_init(figure))
        return INIT_ERROR;

    // vertex_t &verteces = access_to_vertex(figure);
    vertex_t verteces = figure.verteces;
    center_figure center = figure.center;

    triplet to_init_center = {
        .x = -center.x,
        .y = -center.y,
        .z = -center.z
    };
    triplet to_cur_center = {
        .x = center.x,
        .y = center.y,
        .z = center.z
    };

    for (int i = 0; i < verteces.size; i++)
    {
        add_to_vertex(verteces.array[i], to_init_center);
        turn_vertex(verteces.array[i], coeffs);
        add_to_vertex(verteces.array[i], to_cur_center);
    }

    return OK;
}


error save_figure(const figure &figure, const char *filename)
{
    if (!strcmp(filename, ""))
        return EMPTY_NAME_ERROR;

    FILE *f = fopen(filename, "w");
    if (!f)
        return FILE_ERROR;

    if (is_figure_init(figure))
        return INIT_ERROR;

    // vertex_t &verteces = access_to_vertex(figure);
    // edge_t &edges = access_to_edge(figure);
    vertex_t verteces = figure.verteces;
    edge_t edges = figure.edges;
    vertex cur_vertex;

    fprintf(f, "%d\n", verteces.size);
    for (int i = 0; i < verteces.size; i++)
    {
        // cur_vertex = vertex_by_index(verteces, i);
        cur_vertex = verteces.array[i];
        write_vertex_to_file(f, cur_vertex);
    }

    fprintf(f, "\n%d\n", edges.size);
    for (int i = 0; i < edges.size; i++)
        write_edge_to_file(edges, i, f);

    fclose(f);
    return SUCCESS_SAVE;
}
