#include "eskdron.h"

void run_query_engine(t_esk_main *eskdron)
{
    t_esk_q_infos *ptr;
    int db_create;
    
    ptr = eskdron->query;
    db_create = 0;
    while (ptr)
    {
        if (db_create == 1 && ptr->cmd == DB_NAME)
        {
            create_db(eskdron, ptr->s);
            db_create = 0;
        }
        if (ptr->cmd == DB_CREATE)
            db_create = 1;
        ptr = ptr->next;
    }
}
