#include "eskdron.h"

void ft_readline(char **envp)
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
            if (ft_strncmp(RUN, s, ft_strlen(RUN)) == 0)
                run_parsing_query_engine(envp);
            else if (ft_strncmp(EXIT, s, ft_strlen(EXIT)) == 0)
                return (free(s));
            else if (ft_strncmp("\n", s, ft_strlen("\n")) != 0)
                printf("this is not a command\n");
            free(s);
        }
    }
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    ft_putstr_fd("\t\tWELCOME TO _eskDron\n\n", 1);
    ft_putstr_fd("\t\tit's a mini query engine\n", 1);
    ft_putstr_fd("\t\tpowered by the esk_query_language\n", 1);
    ft_putstr_fd("\t\tby Ilyas Founas\n", 1);
    ft_readline(envp);
    return (0);
}
