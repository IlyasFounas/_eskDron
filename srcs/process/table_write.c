#include "eskdron.h"

void add_columns(t_main *esk, char **splited_line, bool *state)
{
    int fd_table_file;
    long first_line_len;
    char *first_line;
    char *ptr_to_dot = ft_strrchr(esk->table_name, '.');
    FILE *file;

    first_line_len = 0;
    if (ptr_to_dot && (ft_strncmp(ptr_to_dot, "nfs", 3) == 0
        || ft_strncmp(ptr_to_dot, "NFS", 3) == 0))
    {
        logger("can't read .NFS files\n", 2);
        *state = false;
        return ;
    }
    fd_table_file = open(esk->table_name, O_APPEND | O_RDWR);
    if (fd_table_file < 0)
    {
        logger("bad file descriptor\n", 2);
        *state = false;
        return ;
    }
    first_line = get_next_line(fd_table_file);
    first_line_len = (long)ft_strlen(first_line); 
    close(fd_table_file);

    file = fopen(esk->table_name, "r+b");
    if (!file)
    {
        *state = false;
        if (first_line)
            free(first_line);
        return ;
    }
    for (int i = 0; splited_line[i]; i++)
    {
        if (i != 0)
        {
            fseek(file, 0, SEEK_END);
            fwrite(" | ", sizeof(char),
                3, file);
        }
        fseek(file, 0, SEEK_END);
        first_line_len = ft_strlen(splited_line[i]);
        fwrite(splited_line[i], sizeof(char),
            first_line_len, file);
        
    }
    logger("<table>", 1);
    printf(" %s successfully updated\n", esk->table_name);
    esk->add_columns_rdy = false;
    fclose(file);
    if (first_line)
        free(first_line);
}

void table_parser()
{
    return ;
}