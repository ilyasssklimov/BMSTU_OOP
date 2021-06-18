#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "drawer.hpp"


class BaseCommand
{
public:
    virtual ~BaseCommand() = default;

    virtual void execute() = 0;
};


class LoadModel : public BaseCommand
{
public:
    explicit LoadModel(std::string name) : name(name) {}
    void execute() override;

private:
    std::string name;
};


class LoadCamera : public BaseCommand
{
public:
    explicit LoadCamera(std::string name) : name(name) {}
    void execute() override;

private:
    std::string name;
};


class LoadScene : public BaseCommand
{
public:
    explicit LoadScene(std::string name) : name(name) {}
    void execute() override;

private:
    std::string name;
};


class DrawScene : public BaseCommand
{
public:
    explicit DrawScene(std::shared_ptr<BaseDrawer> drawer) : drawer(drawer) {};
    void execute() override;

private:
    std::shared_ptr<BaseDrawer> drawer;
};


class ReformModel : public BaseCommand
{
public:
    explicit ReformModel(int &index, Point &shift, Point &scale, Point &rotate) : index(index), shift(shift), scale(scale), rotate(rotate) {};
    void execute() override;

private:
    int index;
    Point shift;
    Point scale;
    Point rotate;
};


class ReformCamera : public BaseCommand
{
public:
    explicit ReformCamera(int &index, Point &shift, Point &rotate) : index(index), shift(shift), rotate(rotate) {};
    void execute() override;

private:
    int index;
    Point shift;
    Point rotate;
};


class RemoveModel : public BaseCommand
{
public:
    explicit RemoveModel(int &index) : index(index) {};
    void execute() override;

private:
    int index;
};


class RemoveCamera : public BaseCommand
{
public:
    explicit RemoveCamera(int &index) : index(index) {};
    void execute() override;

private:
    int index;
};


class SetCamera : public BaseCommand
{
public:
    explicit SetCamera(int &index) : index(index) {};
    void execute() override;

private:
    int index;
};


#endif
