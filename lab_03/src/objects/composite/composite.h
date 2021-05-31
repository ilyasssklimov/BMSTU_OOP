#ifndef COMPOSITE_H
#define COMPOSITE_H


#include "../base_object.h"


using namespace std;


class Composite: public BaseObject
{
public:
    Composite() = default;
    explicit Composite(const shared_ptr<BaseObject> &object);
    explicit Composite(const vector<shared_ptr<BaseObject>> &vector);

    void add(const shared_ptr<BaseObject> &object) override;
    void remove(const vector<shared_ptr<BaseObject>>::iterator &it) override;
    bool is_visible() const override;

    void transform(const Vertex &move, const Vertex &scale, const Vertex &turn) override;
    void accept(shared_ptr<Visitor> visitor) override;

    vector<shared_ptr<BaseObject>>::iterator begin() override;
    vector<shared_ptr<BaseObject>>::iterator end() override;

    vector<shared_ptr<BaseObject>> &get_objects();

private:
    vector<shared_ptr<BaseObject>> objects;
};

#endif
