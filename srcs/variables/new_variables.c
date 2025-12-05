#include "eskdron.h"

t_envp *return_new_node(char *res)
{
    t_envp *new = malloc(sizeof(t_envp));
    if (!new)
        return (NULL);
    new->s = res;
    new->next = NULL;
    return (new);
}

void add_new_variable(t_esk_main *eskdron, char *res)
{
    t_envp *ptr;

    if (!eskdron->envp)
    {
        eskdron->envp = return_new_node(res);
        if (!eskdron->envp)
        {
            free_envp(eskdron->envp);
            gc_crush_malloc(eskdron);
        }
        return ;
    }
    while (eskdron->envp)
    {
        ptr = eskdron->envp;
        eskdron->envp = eskdron->envp->next;
    }
    ptr->next = return_new_node(res);
    if (!ptr->next)
    {
        free_envp(eskdron->envp);
        gc_crush_malloc(eskdron);
    }
}

void new_variable(t_esk_main *eskdron, t_esk_q_infos *ptr)
{
    char *variable;
    char *res;
    char *trim;
    t_esk_q_infos *curr_ptr;

    curr_ptr = ptr->next;
    if (curr_ptr->s)
        variable = ft_strjoin(curr_ptr->s, "=");
    curr_ptr = curr_ptr->next;
    if (curr_ptr->s)
    {
        trim = ft_strtrim(curr_ptr->s, "\"");
        res = ft_strjoin(variable, trim);
        free(variable);
    }
    printf("%s\n", res);
    add_new_variable(eskdron, res);
    if (trim)
        free(trim);
}
