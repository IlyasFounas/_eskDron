#ifndef STRUCTS_H
#define STRUCTS_H

typedef enum e_type
{
	CREATE,
    INSERT,
    UPDATE,
    DELETE,
    DB_NAME,
    T_NAME,
    CONTENT
} t_type;

/**
 * @brief This struct contains the parsing
 * of the esk_query file
 * 
 */
typedef struct s_esk_q_infos
{
    struct s_esk_q_infos    *next;
    char    *s;
    t_type  cmd;
} t_esk_q_infos;

typedef struct s_esk_garbage
{
    struct s_esk_garbage   *next;
    char            *s;
} t_esk_garbage;

typedef struct s_esk_main
{
    t_esk_garbage *garb;
    t_esk_q_infos *query;
    int fd_query_file;
} t_esk_main;

#endif