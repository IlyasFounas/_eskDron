#include "eskdron.h"
#include <sys/types.h>
#include <sys/stat.h>

void create_table(t_esk_main *eskdron, char *s)
{
    pid_t pid;
    char *res;
    char *res2;
    
    pid = fork();
    if (pid == 0)
    {
        // printf("%s\n", s);
        res2 = ft_strjoin("user_space/databases/" , s);
        res = ft_strjoin_sh("touch", res2, 0);
        if (dir_exist(res2) == 0)
            execve("/bin/touch", ft_split(res, ' '), eskdron->envpp);
        free(res2);
        free(res);
        gc_crush_malloc(eskdron);
        exit(0);
    }
}
