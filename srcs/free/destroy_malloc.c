#include "eskdron.h"

void destroy_malloc(t_main *esk)
{
    if (esk->database_name)
    {
        free(esk->database_name);
        esk->database_name = NULL;
    }
    if (esk->state)
    {
        free(esk->state);
        esk->state = NULL;
    }
}
