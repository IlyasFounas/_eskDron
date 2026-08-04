#include "eskdron.h"

char **ft_realloc_tool(char **t, int nb)
{
    int i;
    char **res;

    i = 0;
    res = NULL;
    res = malloc((nb + 2) * sizeof(char *));
    if (!res)
        return (res);
    if (t)
    {
        while (t[i])
        {
            res[i] = ft_strdup(t[i]);
            i++;
        }
    }
    res[nb + 1] = NULL;
    destroy_tab(NULL, t, nb);
    return (res);
}