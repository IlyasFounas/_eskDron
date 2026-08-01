#include "eskdron.h"

void invocation(char *s, int fd, bool print_state)
{
    if (print_state)
        write(fd, "esk_processing: ", 16);
    write(fd, s, ft_strlen(s));
}