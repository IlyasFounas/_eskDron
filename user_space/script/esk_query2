/*Define first for better understanding*/
#define DB "truc"

ESK_DATABASE_CREATE test;

ESK_TABLE_CREATE test.users;

ESK_SELECT fields($DB.table_name.password)
{
    from $DB.table_name
    where $DB.table_name.column = 14,
    $DB.table_name.column.contains("@hotmail.fr")
}

ESK_INSERT table_name(table = $DB.table_name)
{
    table.username = "TRUC";
    table.phone = 14525185;
}

/**
 * #define vars
 * db_create
 * table_create
 * select
 * insert
 * .contains()
 */