#include "eskdron.h"

static void define_type(char *s, t_type *type)
{
    if (ft_strncmp(s, "ESK_DATABASE_CREATE", ft_strlen(s)) == 0)
        *type = DB_CREATE;
    else if (ft_strncmp(s, "ESK_TABLE_CREATE", ft_strlen(s)) == 0)
        *type = CREATE;
    else if (ft_strncmp(s, "#define", ft_strlen(s)) == 0)
        *type = DEFINE;
}

static void modify_type(t_type *type)
{
    if (*type == DB_CREATE)
        *type = DB_NAME;
    else if (*type == CREATE)
        *type = T_NAME;
    else
        *type = CONTENT;
}

int create_tokens(t_esk_main *eskdron, char *s)
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
        q_add_back(&eskdron->query,
            q_new_node(simple_expand(eskdron, tab[i]), type), &fail);
        if (fail == 1)
            return (free_tab(tab, i), fail);
        modify_type(&type);
    }
    free(tab);
    return (fail);
}
