#include "eskdron.h"

// process to create the database
static bool c_database(t_main *esk, char *name, char *fname)
{
    int err;

    err = 0;
    if (!name)
    {
        if (!esk->database_name)
        {
            logger("You should give a name to your database\n", 1);
            return (true);
        }
        else
            fname = ft_strdup(esk->database_name);
    }
    else
        fname = ft_strjoin("user_space/", name, &err);
    if (!fname && err == 1)
    {
        logger("malloc failed occured in the creation of database\n", 2);
        return (false);
    }
    if (access(fname, F_OK) == 0)
    {
        logger("database already exists\n", 1);
        free(fname);
        return (true);
    }
    if (mkdir(fname, 0755) != 0)
    {
        logger("failed to create database\n", 2);
        free(fname);
        return (true);
    }
    logger("successful creation\n", 1);
    free(fname);
    return (true);
}

bool create(t_main *esk, t_create obj, char *name)
{
    FILE *fptr;
    char *fname;
    char *ffname;
    int err;

    fptr = NULL;
    fname = NULL;
    ffname = NULL;
    err = 0;
    if (obj == TABLE)
    {
        // process to create the table
        if (!name)
        {
            logger("you should give a name to your table", 1);
            return (false);
        }
        if (!esk->database_name)
            fname = ft_strjoin("user_space/", name, &err);
        else
        {
            ffname = ft_strjoin(esk->database_name, "/", &err);
            fname = ft_strjoin(ffname, name, &err);
            if (ffname)
                free(ffname);
        }
        if (!fname && err == 1)
        {
            logger("malloc failed occured in the creation of table\n", 2);
            return (false);
        }
        if (access(fname, F_OK) == 0)
        {
            logger("table already exists\n", 1);
            free(fname);
            return (false);
        }
        fptr = fopen(fname, "w");
        if (!fptr)
        {
            logger("failed to create table\n", 2);
            free(fname);
            return (false);
        }
        logger("successful creation\n", 1);
        free(fname);
        fclose(fptr);
    }
    else if (obj == DATABASE)
        return (c_database(esk, name, fname));
    return (true);
}