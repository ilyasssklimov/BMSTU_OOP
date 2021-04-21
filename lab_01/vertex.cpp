#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "figure.h"
#include "vertex.h"



error read_vertex(vertex &cur_vertex, FILE *f)
{
    error rc = OK;
    if (fscanf(f, "%lf%lf%lf", &cur_vertex.x, &cur_vertex.y, &cur_vertex.z) != 3)
        rc = READ_ERROR;
    return rc;
}


void init_verteces(vertex_t &verteces)
{
    verteces.array = nullptr;
    verteces.size = 0;
}


error read_amount_verteces(vertex_t &verteces, FILE *f)
{
    error rc = OK;

    if ((fscanf(f, "%d", &verteces.size)) != 1)
        rc = READ_ERROR;
    else if (verteces.size < 2)
        rc = VERTEX_SIZE_ERROR;

    return rc;
}


error allocate_verteces(vertex_t &verteces)
{
    if (verteces.size < 2)
        return VERTEX_SIZE_ERROR;

    error rc = OK;
    verteces.array = (vertex *)malloc(verteces.size * sizeof(vertex));

    if (!verteces.array)
        rc = ALLOCATE_ERROR;

    return rc;
}


error read_verteces(vertex_t &verteces, FILE *f)
{
    error rc = OK;
    vertex *array_vertex = verteces.array;
    int size_vertex = verteces.size;

    for (int i = 0; i < size_vertex && rc == OK; i++)
        rc = read_vertex(array_vertex[i], f);

    return rc;
}


void free_verteces(vertex_t &verteces)
{
    if (verteces.array)
        free(verteces.array);
}


error get_verteces(vertex_t &verteces, FILE *f)
{
    error rc = OK;

    rc = read_amount_verteces(verteces, f);
    if (rc != OK)
        return rc;

    rc = allocate_verteces(verteces);
    if (rc == OK)
    {
        rc = read_verteces(verteces, f);
        if (rc != OK)
            free_verteces(verteces);
    }

    return rc;
}


/*
vertex &vertex_by_index(vertex_t &verteces, int index)
{
     return verteces.array[index];
}


vertex_t &access_to_vertex(figure &figure)
{
    return figure.verteces;
}
*/

void add_to_vertex(vertex &vertex, const triplet &coeffs)
{
    vertex.x += coeffs.x;
    vertex.y += coeffs.y;
    vertex.z += coeffs.z;
}


void mult_vertex(vertex &vertex, const triplet &coeffs)
{
    vertex.x *= coeffs.x;
    vertex.y *= coeffs.y;
    vertex.z *= coeffs.z;
}


void get_sin_cos(double &sin_angle, double &cos_angle, double angle)
{
    double radians_angle = angle * M_PI / 180;
    sin_angle = sin(radians_angle);
    cos_angle = cos(radians_angle);
}


void turn_vertex_ox(vertex &vertex, const double ox)
{
    double tmp_y = vertex.y,
           tmp_z = vertex.z;
    double sin_angle, cos_angle;
    get_sin_cos(sin_angle, cos_angle, ox);

    vertex.y = tmp_y * cos_angle - tmp_z * sin_angle;
    vertex.z = tmp_y * sin_angle + tmp_z * cos_angle;

}


void turn_vertex_oy(vertex &vertex, const double oy)
{
    double tmp_x = vertex.x,
           tmp_z = vertex.z;
    double sin_angle, cos_angle;
    get_sin_cos(sin_angle, cos_angle, oy);

    vertex.x = tmp_x * cos_angle + tmp_z * sin_angle;
    vertex.z = -tmp_x * sin_angle + tmp_z * cos_angle;
}


void turn_vertex_oz(vertex &vertex, const double oz)
{
    double tmp_x = vertex.x,
           tmp_y = vertex.y;
    double sin_angle, cos_angle;
    get_sin_cos(sin_angle, cos_angle, oz);

    vertex.x = tmp_x * cos_angle - tmp_y * sin_angle;
    vertex.y = tmp_x * sin_angle + tmp_y * cos_angle;
}


void turn_vertex(vertex &vertex, const triplet &coeffs)
{
    turn_vertex_ox(vertex, coeffs.x);
    turn_vertex_oy(vertex, coeffs.y);
    turn_vertex_oz(vertex, coeffs.z);
}


void write_vertex_to_file(FILE *f, const vertex &vertex)
{
    fprintf(f, "%.2lf %.2lf %.2lf\n", vertex.x, vertex.y, vertex.z);
}
