#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H


class BaseCommand
{
public:
    BaseCommand() = default;
    virtual void execute() = 0;

    virtual ~BaseCommand() = default;
};

#endif
