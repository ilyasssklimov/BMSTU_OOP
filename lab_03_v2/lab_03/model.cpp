#include "model.h"

Model::Model(): elements(make_shared<elements>()) {};

Model::Model(const shared_ptr<elements> &elements): elements(elements) {};


void model::accept(shared_ptr<Visitor> visitor)
{
    visitor->visit_model(*this);
}

void model::transform(shared_ptr<Matrix<double>> transform_mtr)
{
    elements->transform(transform_mtr);
}
