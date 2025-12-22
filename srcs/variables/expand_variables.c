#include "eskdron.h"

char *return_res(t_esk_main *eskdron, t_envp *envp, char *var, int i)
{
    char *res;
    int j = -1;
    int y = -1;
    int nb_content = ft_strlen(envp->content);
    int nb_to_malloc = nb_content + ft_strlen(&var[i + 1]);
    int nb_strncmp = ft_strlen(envp->var);

    while (++j <= i)
        nb_to_malloc++;
    res = malloc(((nb_to_malloc + 1) * sizeof(char)));
    if (!res)
        gc_crush_malloc(eskdron);
    esk_add_back(&eskdron->garb, esk_new_node(res));
    j = -1;
    while (++j < i)
        res[j] = var[j];
    while (envp->content[++y])
        res[j + y] = envp->content[y];
    while (var[++i + nb_strncmp])
    {
        res[j + y] = var[i + nb_strncmp];
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
    while (envp)
    {
        if (ft_strncmp(envp->var, &var[i + 1], ft_strlen(envp->var)) == 0)
            return (return_res(eskdron, envp, var, i));
        envp = envp->next;
    }
    return (var);
}
