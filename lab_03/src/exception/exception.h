#ifndef EXCEPTION_H
#define EXCEPTION_H


#include <exception>
#include <string>
using namespace std;


class BaseError: public exception
{
protected:
    string error;

public:
    BaseError(const string &filename, const int line, const char *time, const string &message)
    {
        error = "Error! " + message + "\n" + time + "Filename: " + filename + ", line # " + to_string(line);
    }

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class FileError: public BaseError
{
public:
    FileError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "Error with openning file") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class ParseError: public BaseError
{
public:
    ParseError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "Error with parsing file") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class CameraError: public BaseError
{
public:
    CameraError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "There are no camera") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class CameraDeleteError: public BaseError
{
public:
    CameraDeleteError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "You can\'t delete camera with loaded model") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class ModelError: public BaseError
{
public:
    ModelError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "There are no model") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class ReadModelError: public BaseError
{
public:
    ReadModelError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "Rhere is error while reading model") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};
#endif
