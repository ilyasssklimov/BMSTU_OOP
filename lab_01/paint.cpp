#include "action.h"
#include "wrapper_qt.h"
#include "figure.h"
#include "edge.h"
#include "vertex.h"


// Или поместить в файл figure.cpp
error paint_figure(data_to_draw &data, const figure &figure)
{
    if (is_figure_init(figure))
        return INIT_ERROR;

    int index_start, index_finish;
    vertex vertex_start, vertex_finish;
    vertex_t verteces = figure.verteces;
    scene_to_draw scene = data.scene;

    QtClear(*scene.graph_window);
    for (int i = 0; i < figure.edges.size; i++)
    {
        index_start = index_start_from_edge(figure.edges, i);
        index_finish = index_finish_from_edge(figure.edges, i);

        // verteces = access_to_vertex(figure);
        // vertex_start = vertex_by_index(verteces, index_start);
        // vertex_finish = vertex_by_index(verteces, index_finish);
        vertex_start = verteces.array[index_start];
        vertex_finish = verteces.array[index_finish];

        QtDrawLine(*scene.graph_window,
                   vertex_start.x + vertex_start.z / 3,
                   vertex_start.y + vertex_start.z / 3,
                   vertex_finish.x + vertex_finish.z / 3,
                   vertex_finish.y + vertex_finish.z / 3);
    }

    return OK;
}
