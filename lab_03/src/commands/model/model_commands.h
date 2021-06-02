#ifndef MODEL_COMMANDS_H
#define MODEL_COMMANDS_H


#include <iostream>
#include <memory>
#include "../base_command.h"
#include "./objects/base_object.h"
#include "./objects/model/elements/vertex/vertex.h"


using namespace std;


class LoadModel: public BaseCommand
{
public:
    LoadModel() = delete;
    explicit LoadModel(string filename);
    void execute() override;

    ~LoadModel() override = default;

private:
   string filename;
};


class AddModel: public BaseCommand
{
public:
    AddModel() = delete;
    explicit AddModel(shared_ptr<BaseObject> model);
    void execute() override;

    ~AddModel() override = default;

private:
   shared_ptr<BaseObject> model;
};


class MoveModel: public BaseCommand
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


class ScaleModel: public BaseCommand
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


class TurnModel: public BaseCommand
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


class TransformModel: public BaseCommand
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


class DeleteModel: public BaseCommand
{
public:
    DeleteModel() = delete;
    explicit DeleteModel(const size_t n);
    void execute() override;

    ~DeleteModel() override = default;

private:
    size_t n;
};


class CountModel: public BaseCommand
{
public:
    CountModel() = delete;
    explicit CountModel(shared_ptr<size_t> &count);
    void execute() override;

    ~CountModel() override = default;

private:
    shared_ptr<size_t> &count;
};


#endif
