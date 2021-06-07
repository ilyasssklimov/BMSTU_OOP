#ifndef COMMANDS_H
#define COMMANDS_H

#include "drawer.h"

class base_command
{
public:
    virtual ~base_command() = default;

    virtual void execute() = 0;
};

class LoadModel : public base_command
{
public:
    explicit LoadModel(string name) : name(name) {}
    void execute() override;

private:
    string name;
};

class LoadCamera : public base_command
{
public:
    explicit LoadCamera(string name) : name(name) {}
    void execute() override;

private:
    string name;
};

class LoadScene : public base_command
{
public:
    explicit LoadScene(string name) : name(name) {}
    void execute() override;

private:
    string name;
};

class DrawScene : public base_command
{
public:
    explicit DrawScene(shared_ptr<BaseDrawer> drawer) : drawer(drawer) {};
    void execute() override;

private:
    shared_ptr<BaseDrawer> drawer;
};

class TransformModel : public base_command
{
public:
    explicit TransformModel(long &index, Point &shift, Point &scale, Point &rotate) : index(index), shift(shift), scale(scale), rotate(rotate) {};
    void execute() override;

private:
    long index;
    Point shift;
    Point scale;
    Point rotate;
};

class TransformCamera : public base_command
{
public:
    explicit TransformCamera(long &index, Point &shift, Point &rotate) : index(index), shift(shift), rotate(rotate) {};
    void execute() override;

private:
    long index;
    Point shift;
    Point rotate;
};

class DeleteModel : public base_command
{
public:
    explicit DeleteModel(long &index) : index(index) {};
    void execute() override;

private:
    long index;
};

class DeleteCamera : public base_command
{
public:
    explicit DeleteCamera(long &index) : index(index) {};
    void execute() override;

private:
    long index;
};

class set_camera : public base_command
{
public:
    explicit set_camera(int &index) : index(index) {};
    void execute() override;

private:
    long index;
};

#endif // COMMANDS_H
