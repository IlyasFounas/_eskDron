#include "eskdron.h"

void define_type(char *s, t_type *type)
{
    if (ft_strncmp(s, "ESK_DATABASE_CREATE", ft_strlen(s)) == 0)
        *type = DB_CREATE;
    else if (ft_strncmp(s, "ESK_TABLE_CREATE", ft_strlen(s)) == 0)
        *type = CREATE;
}

int tokens_create(t_esk_main *eskdron, char *s)
{
    int fail;
    int i;
    char **tab;
    t_type type;

    fail = 0;
    i = -1;
    tab = ft_split(s, ' ');
    if (!tab)
        return (1);
    type = CONTENT;
    while (tab[++i])
    {
        define_type(tab[i], &type);
        q_add_back(&eskdron->query, q_new_node(tab[i], type), &fail);
        if (fail == 1)
            break ;
        if (type == DB_CREATE)
            type = DB_NAME;
        else if (type == CREATE)
            type = T_NAME;
        else
            type = CONTENT;
    }
    return (fail);
}
