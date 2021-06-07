#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>
#include <vector>

#include "visitor.hpp"
#include "point.hpp"

class BaseObject
{
public:
    BaseObject() = default;
    ~BaseObject() = default;

    virtual bool add(shared_ptr<BaseObject> object) { return false; }
    virtual bool remove(int index) { return false; }
    virtual vector<shared_ptr<BaseObject>>::iterator begin() {}
    virtual vector<shared_ptr<BaseObject>>::iterator end() {}
    virtual vector<shared_ptr<BaseObject>>::const_iterator cbegin() const {}
    virtual vector<shared_ptr<BaseObject>>::const_iterator cend() const {}

    virtual void accept(shared_ptr<Visitor> visitor) = 0;
    virtual bool is_composite() = 0;
    virtual bool is_visible() = 0;
    virtual void transform(shared_ptr<Matrix<double>> transform_matrix) = 0;
};


class VisibleObject : public BaseObject
{
public:
    VisibleObject() = default;
    ~VisibleObject() = default;

    bool is_visible() override { return true; }
};


class InvisibleObject : public BaseObject
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() = default;

    bool is_visible() override { return false; }
};


#endif
