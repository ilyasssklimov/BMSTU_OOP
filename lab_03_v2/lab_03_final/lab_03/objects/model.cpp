#include "model.hpp"


using namespace std;


Model::Model(): _details(make_shared<Details>()) {}


Model::Model(const shared_ptr<Details> &_details): _details(_details) {}


bool Model::is_composite()
{
    return false;
}


shared_ptr<Details> Model::get_details()
{
    return _details;
}


void Model::accept(shared_ptr<Visitor> _visitor)
{
    _visitor->visit_model(*this);
}


void Model::reform(shared_ptr<Matrix<double>> reform_mtr)
{
    _details->reform(reform_mtr);
}
