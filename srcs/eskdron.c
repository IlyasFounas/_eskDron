#include "eskdron.h"

void ft_readline(t_esk_garbage *garb)
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
            esk_add_back(&garb, esk_new_node(s));
            esk_add_back(&garb, esk_new_node(s));
            esk_add_back(&garb, esk_new_node(s));
            if (ft_strncmp(RUN, s, ft_strlen(RUN)) == 0)
                printf("RUN_THE_ESK_QUERY_ENGINE\n");
            if (ft_strncmp(EXIT, s, ft_strlen(EXIT)) == 0)
            {
                esk_garbage(garb);
                return ;
            }
        }
    }
}

int main(void)
{
    t_esk_garbage *garb;

    garb = esk_new_node(NULL);
    ft_putstr_fd("\t\tWELCOME TO _eskDron\n", 1);
    ft_readline(garb);
    return (0);
}
