#include "eskdron.h"

// char **realloc(char **old_envp, char *new_variable)
// {

// }

void new_variable(t_esk_main *eskdron, t_esk_q_infos *ptr)
{
    (void)eskdron;
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
    if (res)
        free(res);
    if (trim)
        free(trim);
}
