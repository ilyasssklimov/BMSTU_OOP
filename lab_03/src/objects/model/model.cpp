#include "model.h"
#include "./elements/elements.h"
#include "./managers/draw/draw_manager.h"


Model::Model(): elements(new Elements) {}


Model::Model(shared_ptr<Elements> elements): elements(elements) {};


void Model::transform(const Vertex &move, const Vertex &scale, const Vertex &turn)
{
    elements->transform(move, scale, turn);
}


void Model::accept(shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}


shared_ptr<Elements> Model::get_elements() const
{
    return elements;
}
