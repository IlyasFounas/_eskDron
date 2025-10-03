#ifndef ESKDRON_H
# define ESKDRON_H

# define RUN "run"
# define EXIT "exit"

# include "structs.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/*_____esk_garbage_utils_____*/
t_esk_garbage *esk_new_node(char *s);
t_esk_garbage *esk_last_node(t_esk_garbage *garb);
void esk_add_back(t_esk_garbage **garb, t_esk_garbage *new);


/*_____esk_garbage_____*/
void esk_garbage(t_esk_garbage *garb);

#endif