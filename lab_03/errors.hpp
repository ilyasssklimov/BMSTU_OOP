#ifndef ERRORS_HPP
#define ERRORS_HPP


#include <exception>
#include <string>
#include <string.h>


class BaseError : public std::exception
{
protected:
    std::string er_msg;

public:
    BaseError(const std::string &er_msg) : er_msg(er_msg) {}

    const char *what() const noexcept override
    {
        return "Base error";
    }

    const std::string &get_info() const noexcept
    {
        return er_msg;
    }
};


class FileError : public BaseError
{
public:
    FileError(const std::string &er_msg) : BaseError(er_msg) {}

    const char *what() const noexcept override
    {
        return "File error";
    }
};


class BuilderError : public BaseError
{
public:
    BuilderError(const std::string &er_msg) : BaseError(er_msg) {}

    const char *what() const noexcept override
    {
        return "Builder error";
    }
};


class RangeError : public BaseError
{
public:
    RangeError(const std::string &er_msg) : BaseError(er_msg) {}

    const char *what() const noexcept override
    {
        return "Range error";
    }
};


class MemoryError : public BaseError
{
public:
    MemoryError(const std::string &er_msg) : BaseError(er_msg) {}

    const char *what() const noexcept override
    {
        return "Memory error";
    }
};


class NoSecretaryError : public BaseError
{
public:
    explicit NoSecretaryError(std::string &er_msg) : BaseError(er_msg) {}

    const char *what() const noexcept override
    {
        return "There is no secretary set";
    }
};


class NoCameraError : public BaseError
{
public:
    explicit NoCameraError(std::string &er_msg) : BaseError(er_msg) {}

    const char *what() const noexcept override
    {
        return "There is no camera set";
    }
};


class ConfigError : public BaseError
{
public:
    explicit ConfigError(std::string &er_msg) : BaseError(er_msg) {}

    const char *what() const noexcept override
    {
        return "Error in registration process";
    }
};

#endif
