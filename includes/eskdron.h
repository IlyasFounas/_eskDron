#ifndef ESKDRON_H
# define ESKDRON_H

# define RUN "run"
# define EXIT "exit"
# define ESK_FILE "user_space/script/esk_query"

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


//////////////////////CREATE//////////////////////////////
/*_____create_db_table_____*/
void create_db(t_esk_main *eskdron, char *s);
void create_table(t_esk_main *eskdron, char *s);
/*_____create_utils_____*/
t_esk_q_infos *q_new_node(char *content, t_type cmd);
t_esk_q_infos *q_last_node(t_esk_q_infos *main);
void q_add_back(t_esk_q_infos **main, t_esk_q_infos *new, int *pb);
////////////////////////////////////////////////////////


//////////////////////FREE//////////////////////////////
/*_____esk_garbage_utils_____*/
t_esk_garbage *esk_new_node(char *s);
t_esk_garbage *esk_last_node(t_esk_garbage *garb);
void esk_add_back(t_esk_garbage **garb, t_esk_garbage *new);

/*_____esk_garbage_____*/
void esk_garbage(t_esk_garbage *garb);
void gc_main(t_esk_main *eskdron);
////////////////////////////////////////////////////////

//////////////////////RUN///////////////////////////////
/*_____run_parsing_____*/
void run_parsing_query_engine(t_esk_main *eskdron);

/*_____run_query_engine_____*/
void run_query_engine(t_esk_main *eskdron);
////////////////////////////////////////////////////////

//////////////////////TOKENS////////////////////////////
/*_____tokensfree_____*/
void free_tab(char **tab, int i);

/*_____tokens_____*/
int tokens(t_esk_main *eskdron, char *s);
////////////////////////////////////////////////////////


#endif