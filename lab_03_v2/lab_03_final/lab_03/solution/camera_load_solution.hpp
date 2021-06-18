#ifndef CAMERA_LOAD_SOLUTION_H
#define CAMERA_LOAD_SOLUTION_H

#define CAMERA_CFG_PATH "./data/camera_load.cfg"

#include "solution_manager.hpp"


class CameraLoadSolution
{
public:
    CameraLoadSolution() = default;

    std::shared_ptr<LoaderCreator> get_creator();
};

#endif
