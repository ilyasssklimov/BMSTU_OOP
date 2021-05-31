#ifndef MODEL_COMMANDS_H
#define MODEL_COMMANDS_H


#include <iostream>
#include <memory>
#include "../base_command.h"
#include "./objects/base_object.h"
#include "./objects/model/elements/vertex/vertex.h"


using namespace std;


class ModelBaseCommand: public BaseCommand {};


class LoadModel: public ModelBaseCommand
{
public:
    LoadModel() = delete;
    explicit LoadModel(string filename);
    void execute() override;

    ~LoadModel() override = default;

private:
   string filename;
};


class AddModel: public ModelBaseCommand
{
public:
    AddModel() = delete;
    explicit AddModel(shared_ptr<BaseObject> model);
    void execute() override;

    ~AddModel() override = default;

private:
   shared_ptr<BaseObject> model;
};


class MoveModel: public ModelBaseCommand
{
public:
    MoveModel() = delete;
    explicit MoveModel(const double dx, const double dy, const double dz, const size_t n);
    void execute() override;

    ~MoveModel() override = default;

private:
    double dx, dy, dz;
    size_t n;
};


class ScaleModel: public ModelBaseCommand
{
public:
    ScaleModel() = delete;
    explicit ScaleModel(const double kx, const double ky, const double kz, const size_t n);
    void execute() override;

    ~ScaleModel() override = default;

private:
    double kx, ky, kz;
    size_t n;
};


class TurnModel: public ModelBaseCommand
{
public:
    TurnModel() = delete;
    explicit TurnModel(const double ox, const double oy, const double oz, const size_t n);
    void execute() override;

    ~TurnModel() override = default;

private:
    double ox, oy, oz;
    size_t n;
};


class TransformModel: public ModelBaseCommand
{
public:
    TransformModel() = delete;
    explicit TransformModel(const Vertex &move, const Vertex &scale, const Vertex &turn, const size_t n);
    void execute() override;

    ~TransformModel() override = default;

private:
    Vertex move, scale, turn;
    size_t n;
};


class DeleteModel: public ModelBaseCommand
{
public:
    DeleteModel() = delete;
    explicit DeleteModel(const size_t n);
    void execute() override;

    ~DeleteModel() override = default;

private:
    size_t n;
};


#endif
