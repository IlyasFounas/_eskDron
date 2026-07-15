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
# include <stdbool.h>


// free
void destroy_malloc(t_main *esk);

// process
bool interface(t_main *esk, char *line);
bool create(t_main *esk, t_create create, char *name);
void logger(char *s, int fd);

// tools
void trim_line(char *line, char **line_trimed, size_t *line_trimed_length, int *err);
void string_to_null(char *s, size_t length);

#endif