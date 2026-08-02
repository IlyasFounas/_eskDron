#ifndef ESKDRON_H
# define ESKDRON_H

# define RUN "run"
# define EXIT "exit"
# define ESK_FILE "user_space/scripts/query"

# include "macro.h"
# include "structs.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// create
bool    create(t_main *esk, t_create create, char *name);
// free
void    destroy_malloc(t_main *esk);
void    destroy_splited_line(char **splited_line);
// invoke
/**
 * @brief
 * this function is the bridge between the shell parser and the processing.
 * The "processing", mean the writes, the reads, the joins, the actions in the tables
 * 
 * return values : 
 * return -1 if something went wrong in the processing
 * return 0 if everything is okay.
 */
int     powerful_invoke(t_main *esk, char **splited_line);
// read
int     info_columns(t_main *esk, t_table_info *t_info);
// shell_parser
bool    interface(t_main *esk, char *line);
// write
void    add_columns(t_main *esk, char **splited_line, bool *state);
int     insert(t_main *esk, char **splited_line);
// tools
void    trim_line(char *line, char **line_trimed, size_t *line_trimed_length, int *err);
void    string_to_null(char *s, size_t length);
void    logger(char *s, int fd);
char    *trim(char *src, char c, int *trimed_len);

#endif