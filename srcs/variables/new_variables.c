#include "eskdron.h"

t_envp *return_new_node(char *variable, char *trim)
{
    int var_s = ft_strlen(variable);
    int trim_s = ft_strlen(trim);
    t_envp *new;
    
    new = malloc(sizeof(t_envp));
    if (!new)
        return (NULL);
    new->var = malloc((var_s + 1) * sizeof(char));
    if (!new->var)
        return (NULL);
    new->content = malloc((trim_s + 1) * sizeof(char));
    if (!new->content)
        return (NULL);
    ft_strlcpy(new->var, variable, var_s + 1);
    ft_strlcpy(new->content, trim, trim_s + 1);
    new->next = NULL;
    return (new);
}

void add_new_variable(t_esk_main *eskdron, char *variable, char *trim)
{
    t_envp *ptr;

    if (!eskdron->envp)
    {
        eskdron->envp = return_new_node(variable, trim);
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
    ptr->next = return_new_node(variable, trim);
    if (!ptr->next)
    {
        free_envp(eskdron->envp);
        gc_crush_malloc(eskdron);
    }
}

void new_variable(t_esk_main *eskdron, t_esk_q_infos *ptr)
{
    char *variable;
    t_esk_q_infos *curr_ptr;

    curr_ptr = ptr->next;
    if (curr_ptr->s)
        variable = curr_ptr->s;
    curr_ptr = curr_ptr->next;
    if (curr_ptr->s)
        add_new_variable(eskdron, variable, curr_ptr->s);
        
    // PRINT THE DEFINE VARIABLE
    // t_envp *print = eskdron->envp;
    // while (print)
    // {
    //     printf("%s %s\n", print->var, print->content);
    //     print = print->next;
    // }
}
