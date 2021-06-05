#include "camera_builder.h"
#include "./objects/camera/camera.h"


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


shared_ptr<BaseObject> CameraBuilder::get()
{
    // return camera;
}
