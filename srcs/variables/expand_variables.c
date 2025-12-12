#include "eskdron.h"

char *return_res(t_esk_main *eskdron, char *content, char *var, int i)
{
    char *res;
    int j = -1;
    int y = -1;
    int nb_content = ft_strlen(content);
    int nb_to_malloc = nb_content + ft_strlen(&var[i + 1]);

    while (++j < i)
        nb_to_malloc++;
    res = malloc(((nb_to_malloc + 1) * sizeof(char)));
    if (!res)
        gc_crush_malloc(eskdron);
    esk_add_back(&eskdron->garb, esk_new_node(res));
    j = -1;
    while (++j < i)
        res[j] = var[j];
    while (content[++y])
        res[j + y] = content[y];
    while (var[++i])
    {
        res[j + y] = var[i];
        y++;
    }
    res[j + y] = '\0';
    return (res);
}

char *simple_expand(t_esk_main *eskdron, char *var)
{
    t_envp *envp = eskdron->envp;
    int i = -1;
    int expand = 0;
    int nb_strncmp;

    while (var[++i])
    {
        if (var[i] == '$')
        {
            expand = 1;
            break;
        }
    }
    if (expand == 0)
        return (var);
    nb_strncmp = ft_strlen(&var[i + 1]);
    while (envp)
    {
        if (var[nb_strncmp] == '\n')
            nb_strncmp--;
        if (ft_strncmp(envp->var, &var[i + 1], nb_strncmp) != 0)
        {
            char *res = return_res(eskdron, envp->content, var, i);
            printf("%s\n", res);
            exit(0);
            return (return_res(eskdron, envp->content, var, i));
        }
        envp = envp->next;
    }
    return (var);
}
