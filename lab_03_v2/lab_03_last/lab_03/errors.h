#ifndef ERRORS_H
#define ERRORS_H


#include <exception>
#include <string>
#include <string.h>

using namespace std;

class base_error: public exception
{
protected:
    string er_msg;

public:
    base_error(const string &er_msg) : er_msg(er_msg) {}

    const char *what() const noexcept override
    {
        return "Base error";
    }

    const string &get_info() const noexcept
    {
        return er_msg;
    }
};

class file_error : public base_error
{
public:
    file_error(const string &er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "File error";
    }
};

class builder_error : public base_error
{
public:
    builder_error(const string &er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "Builder error";
    }
};

class range_error : public base_error
{
public:
    range_error(const string &er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "Range error";
    }
};

class memory_error : public base_error
{
public:
    memory_error(const string &er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "Memory error";
    }
};

class no_secretary_error : public base_error
{
public:
    explicit no_secretary_error(string &er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "There is no secretary set";
    }
};

class no_camera_error : public base_error
{
public:
    explicit no_camera_error(string &er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "There is no camera set";
    }
};

class config_error : public base_error
{
public:
    explicit config_error(string &er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "Error in registration process";
    }
};

#endif // ERRORS_H
