#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>
#include "base_object.h"


using namespace std;


class Composite: public BaseObject
{
public:
    Composite() = default;
    ~Composite() = default;

    bool add(shared_ptr<BaseObject> obj) override;
    bool remove(long index) override;
    vector<shared_ptr<BaseObject>>::iterator begin() override { return objects.begin(); }
    vector<shared_ptr<BaseObject>>::iterator end() override { return objects.end(); }
    vector<shared_ptr<BaseObject>>::const_iterator cbegin() const override { return objects.begin(); }
    vector<shared_ptr<BaseObject>>::const_iterator cend() const override { return objects.end(); }

    void accept(shared_ptr<Visitor> _visitor) override;
    bool is_composite() override { return true; };
    bool is_visible() override { return false; };
    void transform(shared_ptr<Matrix<double>> reform_mtr) override;

    vector<shared_ptr<BaseObject>> &get_objects() { return objects; };

private:
    vector<shared_ptr<BaseObject>> objects;
};

#endif // COMPOSITE_H
