#include "eskdron.h"

void trim_line(char *line, char **line_trimed, size_t *line_trimed_length, int *err)
{
    size_t line_length;

    line_length = ft_strlen(line);
    if (line_length == 0)
    {
        *err = 1;
        return ;
    }
    if (line_length > *line_trimed_length)
    {
        if (*line_trimed)
            free(*line_trimed);
        *line_trimed = malloc((line_length + 1) * sizeof(char));
        if (!*line_trimed)
        {
            *err = 1;
            return ;
        }
        *line_trimed_length = line_length;
    }
    ft_strlcpy(*line_trimed, line, line_length);
}

void string_to_null(char *s, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        s[i] = '\0';
    }
}