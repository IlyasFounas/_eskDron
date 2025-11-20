/*Define first for better understanding*/
#define DB "test"

ESK_DATABASE_CREATE $DB;

ESK_TABLE_CREATE $DB.users;

ESK_INSERT table_name(table = $DB.table_name)
{
    table.username = "TRUC";
    table.phone = 14525185;
}

ESK_SELECT fields(password)
{
    from $DB.users;                      //Where we going to sort the fields
    where $DB.users.nb_commands < 10;
    $DB.users.mail.contains("@hotmail.fr");
}


/**
 * #define vars
 * db_create
 * table_create
 * select
 * insert
 * .contains()
 */