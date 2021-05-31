#ifndef CAMERA_COMMAND_H
#define CAMERA_COMMAND_H


#include <iostream>
#include <memory>
#include "../base_command.h"
#include "./objects/base_object.h"


using namespace std;


class CameraBaseCommand: public BaseCommand {};


class LoadCamera: public CameraBaseCommand
{
public:
    LoadCamera() = delete;
    explicit LoadCamera(string filename);
    void execute() override;

    ~LoadCamera() override = default;

private:
    string filename;
};


class SetCamera: public CameraBaseCommand
{
public:
    SetCamera() = delete;
    explicit SetCamera(const size_t n);
    void execute() override;

    ~SetCamera() override = default;

private:
    size_t n;
};


class AddCamera: public CameraBaseCommand
{
public:
    AddCamera() = delete;
    explicit AddCamera(shared_ptr<BaseObject> camera);
    void execute() override;

    ~AddCamera() override = default;

private:
    shared_ptr<BaseObject> camera;
};


class DeleteCamera: public CameraBaseCommand
{
public:
    DeleteCamera() = delete;
    explicit DeleteCamera(const size_t n);
    void execute() override;

    ~DeleteCamera() override = default;

private:
    size_t n;
};


class MoveCamera: public CameraBaseCommand
{
public:
    MoveCamera() = delete;
    explicit MoveCamera(const double dx, const double dy, const double dz, const size_t n);
    void execute() override;

    ~MoveCamera() override = default;

private:
    double dx, dy, dz;
    size_t n;
};


class TurnCamera: public CameraBaseCommand
{
public:
    TurnCamera() = delete;
    explicit TurnCamera(const double ox, const double oy, const double oz, const size_t n);
    void execute() override;

    ~TurnCamera() override = default;

private:
    double ox, oy, oz;
    size_t n;
};


#endif
