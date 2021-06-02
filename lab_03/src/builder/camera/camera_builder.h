#ifndef CAMERA_BUILDER_H
#define CAMERA_BUILDER_H


#include "../base_builder.h"


class CameraBuilder : public BaseBuilder {
public:
    CameraBuilder() = default;

    bool is_build() const override;
    void build() override;
    void build_position(double x, double y, double z);

    shared_ptr<BaseObject> get() override;
    ~CameraBuilder() = default;

private:
    std::shared_ptr<Camera> camera;
};

#endif
