#ifndef ERRORS_H
#define ERRORS_H

/*
#define SUCCESS_SAVE       1
#define OK                 0
#define FILE_ERROR        -1
#define READ_ERROR        -2
#define VERTEX_SIZE_ERROR -3
#define EDGE_SIZE_ERROR   -4
#define ALLOCATE_ERROR    -5
#define INPUT_ERROR       -6
#define INIT_ERROR        -7
#define CREATE_ERROR      -8
*/

enum ERROR
{
    OK,
    SUCCESS_SAVE,
    EMPTY_NAME_ERROR,
    FILE_ERROR,
    READ_ERROR,
    VERTEX_SIZE_ERROR,
    EDGE_SIZE_ERROR,
    ALLOCATE_ERROR,
    INPUT_ERROR,
    INIT_ERROR,
    CREATE_ERROR
};


using error = int;

void show_error(const error rc);

#endif
