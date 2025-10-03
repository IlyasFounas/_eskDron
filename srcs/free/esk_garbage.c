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
