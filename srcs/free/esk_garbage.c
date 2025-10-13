#include "eskdron.h"

void esk_garbage(t_esk_garbage *garb)
{
    t_esk_garbage *ptr;
    t_esk_garbage *next;

    if (!garb)
        return ;
    ptr = garb;
    while (ptr)
    {
        next = ptr->next;
        if (ptr->s)
            free(ptr->s);
        free(ptr);
        ptr = next;
    }
}

void esk_query_garbage(t_esk_q_infos *query)
{
    t_esk_q_infos *ptr;
    if (!query)
        return ;
    ptr = query;
    while (query)
    {
        ptr = query->next;
        if (query->s)
            free(query->s);
        free(query);
        query = ptr;
    }
}

void gc_main(t_esk_main *eskdron)
{
    if (eskdron->fd_query_file > -1)
        close(eskdron->fd_query_file);
    esk_garbage(eskdron->garb);
    esk_query_garbage(eskdron->query);
}
