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

void ft_readline(t_main *esk)
{
    int fd;
    int err;
    char *line;
    char *line_trimed;
    size_t line_trimed_length;
    int interface_state;

    fd = 0;
    err = 0;
    line = NULL;
    line_trimed = NULL;
    line_trimed_length = 0;
    interface_state = true;
    while (42)
    {
        if (g_sigint)
        {
            if (line)
                free(line);
            if (line_trimed)
                free(line_trimed);
            destroy_malloc(esk);
            return ;
        }
        if (!esk->add_columns_rdy)
            ft_putstr_fd("_eskDron > ", 0);
        line = get_next_line(fd);
        if (!line)
        {
            destroy_malloc(esk);
            if (line_trimed)
                free(line_trimed);
            return ;
        }
        if (line)
        {
            trim_line(line, &line_trimed, &line_trimed_length, &err);
            if (err == 0)
            {
                interface_state = interface(esk, line_trimed);
                if (!interface_state)
                {
                    free(line);
                    destroy_malloc(esk);
                    if (line_trimed)
                        free(line_trimed);
                    return ;
                }
            }
            string_to_null(line_trimed, line_trimed_length);
            free(line);
        }
        err = 0;
    }
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;

    t_main esk;
    ft_memset(&esk, 0, sizeof(t_main));
    ft_memset(&esk.interf, 0, sizeof(t_interface));
    esk.database_name = NULL;
    esk.table_name = NULL;
    esk.envpp = envp;
    ft_putstr_fd("\t\tWELCOME TO _eskDron\n\n", 1);
    ft_putstr_fd("\t\tit's a very simple query engine\n", 1);
    ft_putstr_fd("\t\tdrive the database with the terminal\n", 1);
    ft_putstr_fd("\t\tby Ilyas Founas\n", 1);
    ft_putstr_fd("\t\t(c 2025-2026)\n", 1);

    set_signals();
    ft_readline(&esk);
    return (0);
}
