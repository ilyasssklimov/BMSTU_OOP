#include <memory>
#include "model_builder.h"

using namespace std;


class ModelBuilder;


bool ModelBuilder::is_build() const
{
    return elements != nullptr;
}


void ModelBuilder::build()
{
    elements = make_shared<Elements>();
}


void ModelBuilder::build_vertex(const double x, const double y, const double z)
{
    if (is_build())
    {
        Vertex vertex(x, y, z);
        elements->add_vertex(vertex);
    }
}


void ModelBuilder::build_edge(const size_t v1, const size_t v2)
{
    if (is_build())
    {
        Edge edge(v1, v2);
        elements->add_edge(edge);
    }
}


shared_ptr<BaseObject> ModelBuilder::get()
{
    // return make_shared<BaseObject>(Model(elements));
}

