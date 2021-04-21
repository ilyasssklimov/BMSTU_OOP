#ifndef FIGURE_H
#define FIGURE_H

#include "errors.h"
#include "vertex.h"
#include "edge.h"
#include "action.h"


// #define PI 3.14159265


struct center_figure
{
    double x;
    double y;
    double z;
};

struct figure
{
    vertex_t verteces;
    edge_t edges;
    center_figure center;
};


figure &init_figure(void);
error is_figure_init(const figure &figure);

error create_figure(figure &figure, const char *filename);
void free_figure(figure &figure);

error carryover_figure(figure &figure, const triplet &coeffs); // const double dx, const double dy, const double dz);
error scale_figure(figure &figure, const triplet &coeffs); // const double kx, const double ky, const double kz);
error turn_figure(figure &figure, const triplet &coeffs); // const double ox, const double oy, const double oz);

error save_figure(const figure &figure, const char *filename);


#endif
