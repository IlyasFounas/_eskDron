#include "eskdron.h"

// create the tokens (create_tokens() function)
// the tokens are created non efficentily and needed a big refacto
// but for the beta it's acceptable
void run_parsing_query_engine(t_esk_main *eskdron)
{
    char *s1;
    char *s;

    eskdron->fd_query_file = open(ESK_FILE,  O_CREAT | O_RDWR | O_APPEND);
    if (eskdron->fd_query_file > -1)
    {
        do {
            s1 = get_next_line(eskdron->fd_query_file);
            s = ft_strtrim(s1, "\n");
            free(s1);
            esk_add_back(&eskdron->garb, esk_new_node(s));
            if (s)
            {
                if (create_tokens(eskdron, s) == 1)
                    break ;
            }
        } while (s);
        run_query_engine(eskdron);
    }
    gc_crush_malloc(eskdron);
    return ;
}

int start_parsing(t_esk_main *eskdron, char *s)
{
    if (s)
    {
        eskdron->garb = esk_new_node(NULL);
        eskdron->query = q_new_node(s, CONTENT);
        if (ft_strncmp(RUN, s, ft_strlen(RUN)) == 0)
            run_parsing_query_engine(eskdron);
        else if (ft_strncmp(EXIT, s, ft_strlen(EXIT)) == 0)
        {
            free_envp(eskdron->envp);
            eskdron->envp = NULL;
            gc_crush_malloc(eskdron);
            return (1);
        }
        else if (ft_strncmp("\n", s, ft_strlen("\n")) != 0)
        {
            printf("this is not a command\n");
            gc_crush_malloc(eskdron);
        }
        else
            gc_crush_malloc(eskdron);
        return (0);
    }
    return (1);
}
