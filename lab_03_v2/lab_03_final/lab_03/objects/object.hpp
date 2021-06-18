#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>
#include <vector>

#include "visitor.hpp"
#include "point.hpp"

class Object
{
public:
    Object() = default;
    ~Object() = default;

    virtual bool add(std::shared_ptr<Object> obj) { return false; }
    virtual bool remove(int index) { return false; }
    virtual std::vector<std::shared_ptr<Object>>::iterator begin() {}
    virtual std::vector<std::shared_ptr<Object>>::iterator end() {}
    virtual std::vector<std::shared_ptr<Object>>::const_iterator cbegin() const {}
    virtual std::vector<std::shared_ptr<Object>>::const_iterator cend() const {}

    virtual void accept(std::shared_ptr<Visitor> _visitor) = 0;
    virtual bool is_composite() = 0;
    virtual bool is_visible() = 0;
    virtual void reform(std::shared_ptr<Matrix<double>> reform_mtr) = 0;
};

class VisibleObject : public Object
{
public:
    VisibleObject() = default;
    ~VisibleObject() = default;

    bool is_visible() override { return true; }
};

class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() = default;

    bool is_visible() override { return false; }
};

#endif
