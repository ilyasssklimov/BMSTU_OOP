#ifndef MODEL_HPP
#define MODEL_HPP

#include "object.hpp"
#include "details.hpp"
#include "visitor.hpp"


class Model: public VisibleObject
{
    friend class Visitor;
public:
    Model();
    explicit Model(const std::shared_ptr<Details> &_details);

    void accept(std::shared_ptr<Visitor> _visitor) override;
    bool is_composite() override { return false; }
    void reform(std::shared_ptr<Matrix<double>> reform_mtr) override;

private:
    std::shared_ptr<Details> get_details() { return _details; }
    std::shared_ptr<Details> _details;
};

#endif
