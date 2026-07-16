#ifndef STRUCTS_H
#define STRUCTS_H

# include <stdbool.h>

typedef struct s_interface
{
    bool add_columns;
    bool creation;
    bool creation_table;
    int i;
} t_interface;

typedef struct s_main
{
    char *state;  //the state message of the execution
    bool add_columns_rdy;
    char *table_name;
    char *database_name;
    char **envpp;
    t_interface interf;
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