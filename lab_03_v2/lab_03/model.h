#ifndef MODEL_H
#define MODEL_H

#include "base_object.h"
#include "elements.h"
#include "visitor.h"

class Model : public VisibleObject
{
    friend class Visitor;
public:
    Model();
    explicit Model(const shared_ptr<Elements> &elements);

    void accept(shared_ptr<Visitor> visitor) override;
    bool is_composite() override { return false; }
    void transform(shared_ptr<Matrix<double>> transform_matrix) override;

private:
    shared_ptr<Elements> get_details() { return elements; }
    shared_ptr<Elements> Elements;
};

#endif
