#include "eskdron.h"
#include <sys/types.h>
#include <sys/stat.h>

int dir_exist(char *s)
{
    struct stat path_stat;

    if (stat(s, &path_stat) != 0)
    {
        return (1);
    }
    if (!S_ISDIR(path_stat.st_mode))
    {
        return (0);
    }
    return (0);
}

void create_db(t_esk_main *eskdron, char *s)
{
    pid_t pid;
    char *res;
    char *res2;
    
    pid = fork();
    if (pid == 0)
    {
        res2 = ft_strjoin("user_space/databases/" , s);
        res = ft_strjoin_sh("mkdir", res2, 0);
        if (dir_exist(res2) == 1)
            execve("/bin/mkdir", ft_split(res, ' '), eskdron->envpp);
        free(res2);
        free(res);
        gc_crush_malloc(eskdron);
        exit(0);
    }
}

