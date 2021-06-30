#ifndef MODEL_HPP
#define MODEL_HPP

#include "object.hpp"
#include "details.hpp"
#include "visitor.hpp"


using namespace std;


class Model: public VisibleObject
{
    friend class Visitor;
public:
    Model();
    explicit Model(const shared_ptr<Details> &_details);

    void accept(shared_ptr<Visitor> _visitor) override;
    bool is_composite() override;
    void reform(shared_ptr<Matrix<double>> reform_mtr) override;

private:
    shared_ptr<Details> get_details();
    shared_ptr<Details> _details;
};

#endif
