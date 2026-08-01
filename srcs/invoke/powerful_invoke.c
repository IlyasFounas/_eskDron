#include "eskdron.h"

void powerful_invoke(t_main *esk, char **splited_line)
{
    int i;
    int err;

    i = 0;
    err = 0;
    while (splited_line[i])
    {
        // if ((ft_strncmp(splited_line[i], "SELECT", 6) == 0 || ft_strncmp(splited_line[i], "DELETE", 6) == 0 ||
        //     ft_strncmp(splited_line[i], "INSERT", 6) == 0 || ft_strncmp(splited_line[i], "UPDATE", 6) == 0 ||
        //     ft_strncmp(splited_line[i], "USE", 3) == 0) || ft_strncmp(splited_line[i], "ADD", 3) == 0)
        //     {
        //         return ;
        //     }
        if (ft_strncmp(splited_line[i], "SELECT", 6) == 0)
        {
            write_invoke(esk, splited_line, &err);
            if (err == 1)
            {
                break;
            }
        }
        i++;
    }
    invocation("you should write a real function", 1, true);
}
