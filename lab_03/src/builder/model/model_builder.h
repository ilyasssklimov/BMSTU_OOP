#ifndef MODEL_BUILDER_H
#define MODEL_BUILDER_H

#include "../base_builder.h"
#include "./objects/model/elements/elements.h"


class ModelBuilder: public BaseBuilder
{
public:
    ModelBuilder() = default;
    bool is_build() const override;
    void build() override;

    void build_vertex(const double x, const double y, const double z);
    void build_edge(const size_t v1, const size_t v2);

    shared_ptr<BaseObject> get() override;

    ~ModelBuilder() = default;

private:
    shared_ptr<Elements> elements;
};

#endif
