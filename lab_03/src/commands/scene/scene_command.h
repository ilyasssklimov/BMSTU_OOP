#ifndef SCENE_COMMAND_H
#define SCENE_COMMAND_H


#include <iostream>
#include <memory>
#include "../base_command.h"
#include "./draw/base_draw.h"


using namespace std;


class DrawScene: public BaseCommand
{
public:
    DrawScene() = delete;
    explicit DrawScene(shared_ptr<BaseDraw> drawer);
    void execute() override;

    ~DrawScene() override = default;

private:
    shared_ptr<BaseDraw> drawer;
};


class LoadScene: public BaseCommand
{
public:
    LoadScene() = delete;
    explicit LoadScene(string filename);
    void execute() override;

    ~LoadScene() override = default;

private:
    string filename;
};

#endif
