#include "eskdron.h"

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
        printf("HERE\n");
        if (ft_strncmp(envp->var, &var[1], ft_strlen(var) - 1) == 0)
            return (envp->content);
        envp = envp->next;
    }
    return (var);
}
