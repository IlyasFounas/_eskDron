#include "eskdron.h"

int info_columns(t_main *esk, t_table_info *t_info)
{
    int fd;
    char *line;

    line = NULL;
    fd = open(esk->table_name, O_RDONLY);
    if (fd < 0)
    {
        return (-1);
    }
    line = get_next_line(fd);
    if (!line)
        return (-1);
    t_info->splited_line = ft_split(line, '|');
    if (!t_info->splited_line)
        return (-1);
    for (int i = 0; t_info->splited_line[i]; i++)
    {
        t_info->columns_nb++;
    }
    close(fd);
    return (0);
}
