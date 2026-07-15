#include "eskdron.h"

/**
 * @brief This function call the query_engine to execute some actions
 */
bool interface(t_main *esk, char *line)
{
    bool use;
    bool state;
    bool creation;
    bool creation_table;
    char **splited_line;

    use = false;
    state = true;
    creation = false;
    creation_table = false;
    splited_line = ft_split(line, ' ');
    if (!splited_line)
    {
        logger("internal process error\n", 2);
        return (true);
    }
    if (splited_line)
    {
        for (int i = 0; splited_line[i]; i++)
        {
            if (i == 0 && ft_strncmp(splited_line[0], "USE", 3) == 0)
                use = true;
            else if (i == 1 && use)
                esk->database_name = ft_strdup(splited_line[1]);
            if (i == 0 && ft_strncmp(splited_line[0], "CREATE", 6) == 0)
                creation = true;
            if (i == 1 && creation && ft_strncmp(splited_line[1], "TABLE", 5) == 0)
                creation_table = true;
            else if (i == 1 && creation && ft_strncmp(splited_line[1], "DATABASE", 8) == 0)
            {
                state = create(esk, DATABASE, splited_line[2]);
                if (!state)
                    break ;
                creation = false;
            }
            else if (i > 0)
                creation = false;
            if (i == 2 && (creation_table))
            {
                state = create(esk, TABLE, splited_line[2]);
                if (!state)
                    break ;
            }
        }
        for (int i = 0; splited_line[i]; i++)
            free(splited_line[i]);
        free(splited_line);
    }
    return (state);
}