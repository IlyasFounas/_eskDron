#include "eskdron.h"

// create the tokens (tokens() function)
// the tokens are created non efficentily and needed a big refacto
// but for the beta it's acceptable
void run_parsing_query_engine(t_esk_main *eskdron)
{
    char *s;

    eskdron->fd_query_file = open(ESK_FILE,  O_CREAT | O_RDWR | O_APPEND);
    if (eskdron->fd_query_file > -1)
    {
        do {
            s = get_next_line(eskdron->fd_query_file);
            esk_add_back(&eskdron->garb, esk_new_node(s));
            if (s)
            {
                if (tokens(eskdron, s) == 1)
                    break ;
            }
        } while (s);
        run_query_engine(eskdron);
    }
    gc_main(eskdron);
    return ;
}
