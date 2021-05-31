#ifndef MODEL_H
#define MODEL_H


#include <iostream>
#include "../base_object.h"
#include "./elements/elements.h"
#include "./visitor/visitor.h"


using namespace std;

/*
class Model: public BaseObject
{
public:
    Model();
    explicit Model(shared_ptr<Elements> elements);

    void transform(const Vertex &move, const Vertex &scale, const Vertex &turn) override;
    void accept(shared_ptr<Visitor> visitor) override;

    shared_ptr<Elements> get_elements() const;

    ~Model() override = default;

private:
    shared_ptr<Elements> elements;
};
*/


class Model : public BaseObject
{
public:
    Model() = default;
    ~Model() = default;
    virtual void transform(const Vertex &move, const Vertex &scale, const Vertex &turn) override;
    // virtual bool isVisible() override;
    virtual void accept(shared_ptr<Visitor> visitor) override;
private:
    shared_ptr<Elements> elements;
};

#endif
