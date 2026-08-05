#include "eskdron.h"

static int write_columns(char **splited_line, FILE *file, int i,
    int first_line_len, bool *put_sep)
{
    (void)first_line_len;
    int trimed_s_line_len;
    char *trimed_s_line;

    trimed_s_line = NULL;
    if (*put_sep)
    {
        fseek(file, 0, SEEK_END);
        fwrite(" | ", sizeof(char),
            3, file);
        *put_sep = false;
    }
    fseek(file, 0, SEEK_END);
    trimed_s_line_len = ft_strlen(splited_line[i]);
    trimed_s_line = trim(splited_line[i], ',', &trimed_s_line_len);
    if (!trimed_s_line)
        return (-1);
    fwrite(trimed_s_line, sizeof(char), trimed_s_line_len, file);
    fwrite(" ", sizeof(char), 1, file);
    free(trimed_s_line);
    return (0);
}

void add_columns(t_main *esk, char **splited_line, bool *state)
{
    bool put_sep;
    int fd_table_file;
    long first_line_len;
    char *first_line;
    char *ptr_to_dot = ft_strrchr(esk->table_name, '.');
    FILE *file;

    put_sep = false;
    first_line_len = 0;
    if (ptr_to_dot && (ft_strncmp(ptr_to_dot, "nfs", 3) == 0
        || ft_strncmp(ptr_to_dot, "NFS", 3) == 0))
    {
        logger("can't read .NFS files\n", 2);
        return ;
    }
    fd_table_file = open(esk->table_name, O_APPEND | O_RDWR);
    if (fd_table_file < 0)
    {
        logger("bad file descriptor\n", 2);
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
    if (first_line_len != 0)
    {
        fseek(file, 0, SEEK_END);
        fwrite("| ", sizeof(char),
            2, file);
    }
    for (int i = 0; splited_line[i]; i++)
    {
        if (write_columns(splited_line, file, i, first_line_len, &put_sep) == -1)
        {
            *state = false;
            if (first_line)
                free(first_line);
            return ;
        }
        if (ft_strchr(splited_line[i], ',') != NULL)
        {
            put_sep = true;
        }
    }
    logger("<table", 1);
    printf(" %s successfully updated>\n", esk->table_name);
    fclose(file);
    if (first_line)
        free(first_line);
}
