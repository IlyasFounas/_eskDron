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


/*___________________CREATE___________________________*/
/*_____create_db_____*/
int dir_exist(char *s);
void create_db(t_esk_main *eskdron, char *s);
/*_____create_table_____*/
void create_table(t_esk_main *eskdron, char *s);
/*_____create_utils_____*/
t_esk_q_infos *q_new_node(char *content, t_type cmd);
t_esk_q_infos *q_last_node(t_esk_q_infos *main);
void q_add_back(t_esk_q_infos **main, t_esk_q_infos *new, int *pb);


/*___________________FREE_____________________________*/
/*_____esk_garbage_utils_____*/
t_esk_garbage *esk_new_node(char *s);
t_esk_garbage *esk_last_node(t_esk_garbage *garb);
void esk_add_back(t_esk_garbage **garb, t_esk_garbage *new);

/*_____esk_garbage_____*/
void free_envp(t_envp *envp);
void esk_garbage(t_esk_garbage *garb);
void gc_crush_malloc(t_esk_main *eskdron);

/*_____run_parsing_____*/
int start_parsing(t_esk_main *eskdron, char *s);

/*_____run_query_engine_____*/
void run_query_engine(t_esk_main *eskdron);


/*______________________TOKENS___________________________*/
/*_____tokensfree_____*/
void free_tab(char **tab, int i);

/*_____tokens_____*/
int create_tokens(t_esk_main *eskdron, char *s);


/*______________________VARIABLES________________________*/
/*_____expand_variables_____*/
char *simple_expand(t_esk_main *eskdron, char *var);

/*_____new_variable_____*/
void new_variable(t_esk_main *eskdron, t_esk_q_infos *ptr);


#endif