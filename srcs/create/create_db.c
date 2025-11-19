#include "eskdron.h"
#include <sys/types.h>
#include <sys/stat.h>

int dir_exist(char *s)
{
    struct stat path_stat;
    if (stat(s, &path_stat) != 0)
    {
        ft_putstr_fd("This is database already exist\n", 2);
        return (0);
    }
    return (1);
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
        if (dir_exist(res2) == 0)
            execve("/bin/mkdir", ft_split(res, ' '), eskdron->envp);
        free(res2);
        free(res);
        gc_main(eskdron);
        exit(0);
    }
}

