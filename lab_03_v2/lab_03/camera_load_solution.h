#ifndef CAMERA_LOAD_SOLUTION_H
#define CAMERA_LOAD_SOLUTION_H

#define CAMERA_CFG_PATH "./data/camera_load.cfg"

#include "solution_manager.h"

class CameraLoadSolution
{
public:
    CameraLoadSolution() = default;

    shared_ptr<LoaderCreator> get_creator();
};

#endif // CAMERA_LOAD_SOLUTION_H
