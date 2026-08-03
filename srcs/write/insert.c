#include "eskdron.h"

int insert(t_main *esk, char **splited_line)
{
    (void)splited_line;
    t_table_info t_info;

    ft_memset(&t_info, sizeof(t_table_info), 0);
    if (info_columns(esk, &t_info) == -1)
        return (-1);
    destroy_splited_line(t_info.splited_line);
    return (0);
}