#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_main
{
    void *ptr;
    char **envpp;
} t_main;

typedef enum s_create
{
    DATABASE,
    TABLE
} t_create;

typedef struct s_obj
{
    void *smth;
} t_obj;

#endif