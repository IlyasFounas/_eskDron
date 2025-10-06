#include "eskdron.h"

void esk_garbage(t_esk_garbage *garb)
{
    t_esk_garbage *ptr;
    if (!garb)
        return ;
    ptr = garb;
    while (garb)
    {
        ptr = garb->next;
        if (garb->s)
            free(garb->s);
        free(garb);
        garb = ptr;
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
        free(query);
        query = ptr;
    }
}

void gc_main(t_esk_main *eskdron)
{
    esk_garbage(eskdron->garb);
    esk_query_garbage(eskdron->query);
}
