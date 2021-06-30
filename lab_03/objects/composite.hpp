#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <vector>
#include "object.hpp"


class Composite : public Object
{
public:
    Composite() = default;
    ~Composite() = default;

    bool add(std::shared_ptr<Object> obj) override;
    bool remove(int index) override;
    std::vector<std::shared_ptr<Object>>::iterator begin() override { return objects.begin(); }
    std::vector<std::shared_ptr<Object>>::iterator end() override { return objects.end(); }
    std::vector<std::shared_ptr<Object>>::const_iterator cbegin() const override { return objects.begin(); }
    std::vector<std::shared_ptr<Object>>::const_iterator cend() const override { return objects.end(); }

    void accept(std::shared_ptr<Visitor> _visitor) override;
    bool is_composite() override { return true; };
    bool is_visible() override { return false; };
    void reform(std::shared_ptr<Matrix<double>> reform_mtr) override;

    std::vector<std::shared_ptr<Object>> &get_objects() { return objects; };

private:
    std::vector<std::shared_ptr<Object>> objects;
};

#endif
