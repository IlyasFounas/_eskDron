#include "eskdron.h"

void logger(char *s, int fd)
{
    write(fd, "eskdron_query_engine: ", 22);
    write(fd, s, ft_strlen(s));
}