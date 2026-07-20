#include "eskdron.h"

static void interface_creation(t_main *esk, bool *state, char **splited_line)
{
    t_interface *interf;
    int i;
    
    if (!state)
        return ;
    interf = &esk->interf;
    i = interf->i;
    if (i == 0 && ft_strncmp(splited_line[0], "CREATE", 6) == 0)
        interf->creation = true;
    if (i == 1 && interf->creation && ft_strncmp(splited_line[1], "TABLE", 5) == 0)
        interf->creation_table = true;
    else if (i == 1 && interf->creation && ft_strncmp(splited_line[1], "DATABASE", 8) == 0)
    {
        *state = create(esk, DATABASE, splited_line[2]);
        if (!*state)
            return ;
        interf->creation = false;
    }
    else if (i > 0)
        interf->creation = false;
    if (i == 2 && (interf->creation_table))
    {
        *state = create(esk, TABLE, splited_line[2]);
        if (!*state)
            return ;
    }
}

static bool interface_add_columns(t_main *esk, bool *state, char **splited_line)
{
    int err = 0;
    t_interface *interf = &esk->interf;

    if (ft_strncmp(splited_line[interf->i], "ADD", 3) == 0)
    {
        if (splited_line[interf->i + 1]
            && ft_strncmp(splited_line[interf->i + 1], "COLUMNS", 7) == 0)
        {
            if (splited_line[interf->i + 2]
                && ft_strncmp(splited_line[interf->i + 2], "TO", 2) != 0)
            {
                interf->add_columns = false;
            }
            else
                interf->add_columns = true;
        }
        if (!interf->add_columns)
        {
            write(1, "you should write like that : ADD COLUMNS TO table\n", 50);
            return (false);
        }
    }
    if (interf->add_columns)
    {
        if (!splited_line[interf->i + 3])
        {
            write(1, "you should name the table you to add columns to\n", 48);
            return (false);
        }
        else
        {
            if (!esk->database_name)
            {
                logger("you should USE an exsiting database", 1);
                return (false);
            }
            write(0, "< give the name of the columns >\n", 33);
            char *tmp = ft_strjoin(esk->database_name, "/", &err);
            if (err == 1)
            {
                *state = false;
                return (true);
            }
            if (esk->table_name)
                free(esk->table_name);
            esk->table_name = ft_strjoin(tmp, splited_line[interf->i + 3], &err);
            if (err == 1)
            {
                *state = false;
                return (true);
            }
            esk->add_columns_rdy = true;
            interf->i += 3;
            free(tmp);
        }
        interf->add_columns = false;
    }
    return (true);
}


/**
 * @brief This function call the query_engine to execute some actions
 */
bool interface(t_main *esk, char *line)
{
    int err;
    bool use;
    bool state;
    char **splited_line;

    err = 0;
    use = false;
    state = true;
    splited_line = ft_split(line, ' ');
    if (!splited_line)
    {
        logger("internal process error\n", 2);
        return (true);
    }
    if (splited_line)
    {
        esk->interf.add_columns = false;
        esk->interf.creation = false;
        esk->interf.creation_table = false;
        esk->interf.i = 0;
        while (splited_line[esk->interf.i])
        {
            if (esk->interf.i == 0 && ft_strncmp(splited_line[0], "USE", 3) == 0)
                use = true;
            else if (esk->interf.i == 1 && use)
            {
                if (esk->database_name)
                {
                    free(esk->database_name);
                    esk->database_name = NULL;
                }
                esk->database_name = ft_strjoin("user_space/", splited_line[1], &err);
                if (err == 1)
                {
                    state = false;
                    break ;
                }
            }
            if (esk->add_columns_rdy)
            {
                add_columns(esk, splited_line, &state);
                esk->add_columns_rdy = false;
                if (!state)
                    break ;
            }
            if (!interface_add_columns(esk, &state, splited_line))
                break ;
            interface_creation(esk, &state, splited_line);
            if (!state)
                break ;
            esk->interf.i++;
        }
        powerful_invoke(esk, splited_line);
        for (int i = 0; splited_line[i]; i++)
            free(splited_line[i]);
        free(splited_line);
    }
    return (state);
}
