#include "eskdron.h"

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
        free(res2);
        execve("/bin/mkdir", ft_split(res, ' '), eskdron->envp);
        free(res);
        gc_main(eskdron);
        exit(0);
    }
}
