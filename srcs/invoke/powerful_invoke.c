#include "eskdron.h"

void powerful_invoke(t_main *esk, char **splited_line)
{
    int i;
    (void)esk;
    i = 0;
    while (splited_line[i])
    {
        if (i == 0 && 
            (ft_strncmp(splited_line[i], "SELECT", 6) != 0 || ft_strncmp(splited_line[i], "DELETE", 6) != 0 ||
            ft_strncmp(splited_line[i], "INSERT", 6) != 0 || ft_strncmp(splited_line[i], "UPDATE", 6) != 0))
            {
                invocation("you should write a real function", 1, true);
                return ;
            }
        i++;
    }
}
