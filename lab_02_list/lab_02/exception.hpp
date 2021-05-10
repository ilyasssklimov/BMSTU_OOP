#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP


#include <string>
#include <exception>

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


class MemoryError: public BaseError
{
public:
    MemoryError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "Incorrect allocation memory") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class PointerError: public BaseError
{
public:
    PointerError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "Incorrect pointer in parametrs") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class SizeError: public BaseError
{
public:
    SizeError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "Incorrect size in parametrs (should be positive)") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class EmptyError: public BaseError
{
public:
    EmptyError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "List can't be empty") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class IteratorError: public BaseError
{
public:
    IteratorError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "Incorrect iterator in parametrs") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


class IndexError: public BaseError
{
public:
    IndexError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "Size in parametrs is more than size of list") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};


/*
class RemoveError: public BaseError
{
public:
    RemoveError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "There is no such element") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};
*/


class SharedPtrError: public BaseError
{
public:
    SharedPtrError(const string &filename, const int line, const char *time):
        BaseError(filename, line, time, "Shared_ptr on which weak_ptr is based is invalid") {};

    virtual const char *what() const noexcept override
    {
        return error.c_str();
    }
};



#endif
