#include "eskdron.h"

void free_tab(char **tab, int i)
{
    if (!tab)
        return ;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}
