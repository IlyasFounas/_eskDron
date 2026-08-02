#include "eskdron.h"

void destroy_splited_line(char **splited_line)
{
    for (int i = 0; splited_line[i]; i++)
        free(splited_line[i]);
    free(splited_line);
}
