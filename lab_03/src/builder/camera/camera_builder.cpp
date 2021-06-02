#include "camera_builder.h"


bool CameraBuilder::is_build() const
{
    return camera == nullptr;
}


void CameraBuilder::build()
{
    camera = make_shared<Camera>();
}


void CameraBuilder::build_position(double x, double y, double z)
{

}

std::shared_ptr<BaseObject> CameraBuilder::get()
{
    // return camera;
}
