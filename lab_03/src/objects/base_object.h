#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H


#include <iostream>
#include <memory>
#include <vector>
#include "./model/elements/vertex/vertex.h"
#include "./visitor/visitor.h"


using namespace std;

class BaseObject;


class BaseObject
{
public:
    BaseObject() = default;

    virtual void add(const shared_ptr<BaseObject> &);
    virtual void remove(const vector<shared_ptr<BaseObject>>::iterator &);
    virtual bool is_visible() const;

    virtual void transform(const Vertex &move, const Vertex &scale, const Vertex &turn) = 0;
    virtual void accept(shared_ptr<Visitor> visitor) = 0;

    virtual vector<shared_ptr<BaseObject>>::iterator begin();
    virtual vector<shared_ptr<BaseObject>>::iterator end();

    virtual ~BaseObject() = default;
};

#endif
