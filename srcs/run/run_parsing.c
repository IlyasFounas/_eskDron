#include "eskdron.h"

char *return_s(t_esk_main *eskdron, char *s)
{
    char *res;
    int i = -1;
    int y = -1;
    bool backslash = false;
    int nb_to_malloc = ft_strlen(s);
    
    if (!s)
        return (NULL);
    while (s[++y])
        if (s[y] == '\n')
            backslash = true;
    if (backslash)
        nb_to_malloc--;
    res = malloc((nb_to_malloc) * sizeof(char));
    if (!res)
        gc_crush_malloc(eskdron);
    while (++i < nb_to_malloc)
        res[i] = s[i];
    res[i] = '\0';
    return (res);
}

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
            s = return_s(eskdron, s1);
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
