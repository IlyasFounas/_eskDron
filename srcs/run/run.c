#include "eskdron.h"

void print_tokens(t_esk_main *eskdron)
{
    while (eskdron->query)
    {
        printf("%s %d\n", eskdron->query->s, eskdron->query->cmd);
        eskdron->query = eskdron->query->next;
    }
}

void run_query_engine(t_esk_main *eskdron)
{
    t_esk_q_infos *ptr;
    int db_create;
    
    ptr = eskdron->query;
    db_create = 0;
    while (ptr)
    {
        if (db_create == 1 && ptr->cmd == DB_NAME)
        {
            create_db(eskdron, ptr->s);
            db_create = 0;
        }
        if (ptr->cmd == DB_CREATE)
            db_create = 1;
        ptr = ptr->next;
    }
}

void run_parsing_query_engine(char **envp)
{
    t_esk_main eskdron;
    char *s;

    ft_memset(&eskdron, 0, sizeof(t_esk_main));
    eskdron.garb = esk_new_node(NULL);
    eskdron.query = q_new_node(NULL, CONTENT);
    eskdron.fd_query_file = open(ESK_FILE,  O_CREAT | O_RDWR | O_APPEND);
    eskdron.envp = envp;
    if (eskdron.fd_query_file > -1)
    {
        do {
            s = get_next_line(eskdron.fd_query_file);
            esk_add_back(&eskdron.garb, esk_new_node(s));
            if (s)
            {
                if (tokens_create(&eskdron, s) == 1)
                    break ;
            }
        } while (s);
        // print_tokens(&eskdron);
        run_query_engine(&eskdron);
    }
    gc_main(&eskdron);
    return ;
}
