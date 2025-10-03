#include "eskdron.h"

t_esk_garbage *esk_new_node(char *s)
{
    t_esk_garbage *node;
    
    node = malloc(sizeof(t_esk_garbage));
    if (!node)
    {
        ft_putstr_fd("malloc error\n", 2);
        return (NULL);
    }
    node->s = s;
    node->next = NULL;
    return (node);
}

t_esk_garbage *esk_last_node(t_esk_garbage *garb)
{
    t_esk_garbage *ptr;

    if (!garb)  
        return (NULL);
    ptr = garb;
    while (garb)
    {
        ptr = garb;
        garb = garb->next;
    }
    return (ptr);
}

void esk_add_back(t_esk_garbage **garb, t_esk_garbage *new)
{
    if (!new)
    {
        esk_garbage(*garb);
        exit(1);
    }
    if (!garb && new)
        *garb = new;
    else
    {
        esk_last_node(*garb)->next = new;
    }
}
