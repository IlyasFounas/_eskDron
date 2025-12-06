#include "eskdron.h"

void free_envp(t_envp *envp)
{
    t_envp *ptr;

    while (envp)
    {
        ptr = envp;
        envp = envp->next;
        if (ptr->var)
            free(ptr->var);
        if (ptr->content)
            free(ptr->content);
        free(ptr);
    }
    return ;
}

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

void gc_crush_malloc(t_esk_main *eskdron)
{
    if (eskdron->fd_query_file > -1)
        close(eskdron->fd_query_file);
    esk_garbage(eskdron->garb);
    esk_query_garbage(eskdron->query);
    eskdron->query = NULL;
    eskdron->garb = NULL;
}
