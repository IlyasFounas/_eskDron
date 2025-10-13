#include "eskdron.h"

void ft_readline(t_esk_main *eskdron)
{    
    int fd;
    char *s;

    fd = 1;
    s = NULL;
    while (42)
    {
        s = get_next_line(fd);
        if (s)
        {
            eskdron->garb = esk_new_node(NULL);
            eskdron->query = q_new_node(NULL, CONTENT);
            if (ft_strncmp(RUN, s, ft_strlen(RUN)) == 0)
                run_parsing_query_engine(eskdron);
            else if (ft_strncmp(EXIT, s, ft_strlen(EXIT)) == 0)
            {
                gc_main(eskdron);
                return (free(s));
            }
            else if (ft_strncmp("\n", s, ft_strlen("\n")) != 0)
            {
                printf("this is not a command\n");
                gc_main(eskdron);
            }
            free(s);
        }
    }
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    t_esk_main eskdron;

    ft_memset(&eskdron, 0, sizeof(t_esk_main));
    eskdron.envp = envp;
    ft_putstr_fd("\t\tWELCOME TO _eskDron\n\n", 1);
    ft_putstr_fd("\t\tit's a mini query engine\n", 1);
    ft_putstr_fd("\t\tpowered by the esk_query_language\n", 1);
    ft_putstr_fd("\t\tby Ilyas Founas\n", 1);
    ft_readline(&eskdron);
    return (0);
}
