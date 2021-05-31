#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H


#include <iostream>
#include <memory>
#include <vector>
#include "./model/elements/vertex/vertex.h"
#include "./visitor/visitor.h"


using namespace std;


class BaseObject
{
public:
    BaseObject() = default;

    virtual void add(const shared_ptr<BaseObject> &) {};
    virtual void remove(const vector<shared_ptr<BaseObject>>::iterator &) {};
    virtual bool is_visible() const { return false };

    virtual void transform(const Vertex &move, const Vertex &scale, const Vertex &turn) = 0;
    virtual void accept(shared_ptr<Visitor> visitor) = 0;

    virtual vector<shared_ptr<BaseObject>>::iterator begin() { return vector<shared_ptr<BaseObject>>::iterator() };
    virtual vector<shared_ptr<BaseObject>>::iterator end() { return vector<shared_ptr<BaseObject>>::iterator() };

    virtual ~BaseObject() = default;
};

#endif
