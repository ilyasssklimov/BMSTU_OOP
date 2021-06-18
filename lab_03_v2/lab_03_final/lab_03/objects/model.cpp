#include "model.hpp"

Model::Model()
    :_details(std::make_shared<Details>())
{
}

Model::Model(const std::shared_ptr<Details> &_details)
    :_details(_details)
{
}

void Model::accept(std::shared_ptr<Visitor> _visitor)
{
    _visitor->visit_model(*this);
}

void Model::reform(std::shared_ptr<Matrix<double>> reform_mtr)
{
    _details->reform(reform_mtr);
}
