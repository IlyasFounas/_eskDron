#include "eskdron.h"

static void print_tab(char **t)
{
    for (int i = 0; t[i]; i++)
        printf("%s ", t[i]);
    printf("\n");
}

int insert(t_main *esk, char **splited_line)
{
    int j;
    int y;
    bool fill_columns;
    t_table_info t_info;
    char **values;
    char **columns;

    j = 0;
    y = 0;
    fill_columns = false;
    values = NULL;
    columns = NULL;
    ft_memset(&t_info, sizeof(t_table_info), 0);
    printf("HERE\n");
    if (info_columns(esk, &t_info, splited_line) == -1)
        return (-1);
    for (int i = 0; splited_line[i]; i++)
    {
        if (ft_strncmp(splited_line[i], "as", 2) == 0)
        {
            fill_columns = true;
        }
        else
        {
            if (fill_columns)
            {
                columns = ft_realloc_tool(columns, j);
                columns[j] = ft_strdup(splited_line[i]);
                if (!columns[j])
                {
                    destroy_tab(&t_info, columns, j);
                    destroy_tab(&t_info, values, y);
                    return (-1);
                }
                j++;
            }
            else
            {
                values = ft_realloc_tool(values, y);
                values[y] = ft_strdup(splited_line[i]);
                if (!values[y])
                {
                    destroy_tab(&t_info, columns, j);
                    destroy_tab(&t_info, values, y);
                    return (-1);
                }
                y++;
            }
        }
    }
    print_tab(values);
    print_tab(columns);
    destroy_tab(&t_info, columns, j);
    destroy_tab(&t_info, values, y);
    destroy_splited_line(t_info.splited_line);
    return (0);
}
