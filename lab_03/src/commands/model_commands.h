#ifndef MODEL_COMMANDS_H
#define MODEL_COMMANDS_H


#include <iostream>
#include <memory>
#include "commands/base_command.h"
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
    explicit AddModel(shared_ptr<BaseObject>);
    void execute() override;

    ~LoadModel() override = default;

private:
   string filename;
};
#endif
