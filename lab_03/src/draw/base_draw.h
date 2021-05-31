#ifndef BASE_DRAW_H
#define BASE_DRAW_H


#include "./objects/model/elements/vertex/vertex.h"


class BaseDraw
{
public:
    BaseDraw() = default;
    virtual void create_line(const Vertex &start, const Vertex &finish) = 0;
    virtual void clear_scene() = 0;

    ~BaseDraw() = default;
};


#endif
