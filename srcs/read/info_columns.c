#include "eskdron.h"

int info_columns(t_main *esk, t_table_info *t_info)
{
    int fd;
    (void)t_info;
    fd = open(esk->table_name, O_RDONLY);
    if (fd < 0)
    {
        return (-1);
    }
    close(fd);
    return (0);
}
