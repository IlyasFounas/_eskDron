#include "eskdron.h"

void run_parsing_query_engine()
{
    t_esk_main eskdron;
    char *s;
    int pb;

    ft_memset(&eskdron, 0, sizeof(t_esk_main));
    eskdron.garb = esk_new_node(NULL);
    eskdron.query = q_new_node(NULL, CONTENT);
    eskdron.fd_query_file = open(ESK_FILE,  O_CREAT | O_RDWR | O_APPEND);
    if (eskdron.fd_query_file > -1)
    {
        do {
            s = get_next_line(eskdron.fd_query_file);
            esk_add_back(&eskdron.garb, esk_new_node(s));
            q_add_back(&eskdron.query, q_new_node(s, CONTENT), &pb);
            if (pb == 1)
                break ;
            if (s)
            {
                printf("%s\n", s);
            }
        } while (s);
    }
    close(eskdron.fd_query_file);
    gc_main(&eskdron);
    return ;
}
