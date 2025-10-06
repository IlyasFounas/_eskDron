#include "eskdron.h"

t_esk_q_infos *q_new_node(char *content, t_type cmd)
{
    t_esk_q_infos *node;
    
    node = malloc(sizeof(t_esk_q_infos));
    if (!node)
    {
        ft_putstr_fd("malloc error\n", 2);
        return (NULL);
    }
    node->s = content;
    node->cmd = cmd;
    node->next = NULL;
    return (node);
}

t_esk_q_infos *q_last_node(t_esk_q_infos *main)
{
    t_esk_q_infos *ptr;

    if (!main)  
        return (NULL);
    ptr = main;
    while (main)
    {
        ptr = main;
        main = main->next;
    }
    return (ptr);
}

void q_add_back(t_esk_q_infos **main, t_esk_q_infos *new, int *pb)
{
    if (!new)
    {
        *pb = 1;
        return ;
    }
    if (!main && new)
        *main = new;
    else
    {
        q_last_node(*main)->next = new;
    }
}
