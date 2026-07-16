#include "eskdron.h"

void destroy_malloc(t_main *esk)
{
    if (esk->database_name)
    {
        free(esk->database_name);
        esk->database_name = NULL;
    }
    if (esk->table_name)
    {
        free(esk->table_name);
        esk->table_name = NULL;
    }
    if (esk->state)
    {
        free(esk->state);
        esk->state = NULL;
    }
    // if (esk->splited_line)
    // {
    //     for (int i = 0; splited_line[i]; i++)
    //         free(splited_line[i]);
    //     free(splited_line);
    // }
}
