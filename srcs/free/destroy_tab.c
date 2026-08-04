#include "eskdron.h"

void destroy_tab(t_table_info *t_info, char **t, int i)
{
    if (t)
    {
        while (i >= 0)
        {
            free(t[i]);
            i--;
        }
        free(t);
    }
    if (t_info)
    {
        if (t_info->splited_line)
        {
            destroy_splited_line(t_info->splited_line);
            t_info->splited_line = NULL;            
        }
    }
}