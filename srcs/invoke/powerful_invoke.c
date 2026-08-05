#include "eskdron.h"

int powerful_invoke(t_main *esk, char **splited_line)
{
    int i;

    i = 0;
    while (splited_line[i])
    {
        if (ft_strncmp(splited_line[i], "INSERT", 6) == 0)
        {
            if (splited_line[i + 1])
            {
                if (insert(esk, &splited_line[i + 1]) == -1)
                    return (-1);
                return (0);
            }
            return (-1);
        }
        i++;
    }
    return (0);
}
