#ifndef ACTION_H
#define ACTION_H

#include "errors.h"
#include <QGraphicsScene>


/*
#define DRAW      1
#define CREATE    2
#define CARRYOVER 3
#define SCALE     4
#define TURN      5
#define SAVE      6
#define QUIT      7
*/


enum ACTION
{
    DRAW,
    CREATE,
    CARRYOVER,
    SCALE,
    TURN,
    SAVE,
    QUIT,
    UNKNOWN
};


struct scene_to_draw
{
    QGraphicsScene *graph_window;
};


struct triplet
{
    double x;
    double y;
    double z;
};

struct data_to_draw
{
    // QGraphicsScene *graph_window;
    scene_to_draw scene;
    char *filename;
    triplet coefficients;
};


error do_action(data_to_draw &data, const int action);


#endif
