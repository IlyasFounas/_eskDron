#include "eskdron.h"

static void find_tablename(t_main *esk, char **splited_line)
{
    int err;
    char *tmp;
    bool fill_tablename;

    err = 0;
    tmp = NULL;
    fill_tablename = false;
    for (int i = 0; splited_line[i]; i++)
    {
        if (fill_tablename)
        {
            tmp = ft_strjoin("/", splited_line[i], &err);
            if (!tmp)
                return;
            if (esk->table_name)
                free(esk->table_name);
            esk->table_name = ft_strjoin(esk->database_name, tmp, &err);
            free(tmp);
            return ;
        }
        if (ft_strncmp(splited_line[i], "into", 4) == 0)
            fill_tablename = true;
    }
}

int info_columns(t_main *esk, t_table_info *t_info, char **splited_line)
{
    int fd;
    char *line;

    line = NULL;

    find_tablename(esk, splited_line);
    if (!esk->table_name || access(esk->table_name, F_OK) != 0)
    {
        logger("This table don't exist\n", 1);
        return (-1);
    }
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
    free(line);
    return (0);
}
