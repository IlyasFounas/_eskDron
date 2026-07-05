#include "eskdron.h"
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t g_sigint = 0;

void sigint_handler(int sig)
{
    (void)sig;
    g_sigint = 1;
    write(1, "\n", 1);
}

void set_signals(void)
{
    struct sigaction sa;

    ft_memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(SIGINT, &sa, NULL);
    signal(SIGQUIT, SIG_IGN);
}

// Every new lines call the garbage collector
// To don't take all the memory, 
// when the execution finish we free all the memory
void ft_readline(t_main *esk)
{    
    int fd;
    char *s;

    fd = 1;
    s = NULL;
    (void)esk;
    while (42)
    {
        s = get_next_line(fd);
        if (g_sigint)
        {
            return ;
        }
        if (s)
        {
            printf("%s\n", s);
        }
    }
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;

    t_main esk;
    ft_memset(&esk, 0, sizeof(t_main));
    esk.envpp = envp;
    ft_putstr_fd("\t\tWELCOME TO _eskDron\n\n", 1);
    ft_putstr_fd("\t\tit's a very simple query engine\n", 1);
    ft_putstr_fd("\t\tpowered by the esk_language\n", 1);
    ft_putstr_fd("\t\tby Ilyas Founas\n", 1);
    ft_putstr_fd("\t\t(c 2025-2026)\n", 1);

    set_signals();
    ft_readline(&esk);
    return (0);
}
