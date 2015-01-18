#include <stdio.h>
#include <where.h>
#include <utils.h>

static void _sandbox_sqlite_where_add(sandbox_sqlite_where_t *where, char *clause, char *logicalOperator, char *argv)
{
    if (sandbox_utils_array_size_s(where->conditions) > 0) {
        sandbox_utils_array_push_s(where->logicalOperators, logicalOperator);
    }
    if (argv != NULL) {
        sandbox_utils_array_push_s(where->values, argv);
    }
    sandbox_utils_array_push_s(where->conditions, clause);
}

sandbox_sqlite_where_t sandbox_sqlite_where_init()
{
    sandbox_sqlite_where_t where = {
            {}, {}, {}
    };
    return where;
}

void sandbox_sqlite_where_and(sandbox_sqlite_where_t *where, char* clause)
{
    _sandbox_sqlite_where_add(where, clause, "AND", NULL);
}

void sandbox_sqlite_where_and_s(sandbox_sqlite_where_t *where, char* clause, char* argv)
{
    _sandbox_sqlite_where_add(where, clause, "AND", argv);
}

void sandbox_sqlite_where_and_i(sandbox_sqlite_where_t *where, char* clause, int argv)
{
    _sandbox_sqlite_where_add(where, clause, "AND", sandbox_utils_i_to_s(argv));
}

void sandbox_sqlite_where_or(sandbox_sqlite_where_t *where, char* clause)
{
    _sandbox_sqlite_where_add(where, clause, "OR", NULL);
}

void sandbox_sqlite_where_or_s(sandbox_sqlite_where_t *where, char* clause, char* argv)
{
    _sandbox_sqlite_where_add(where, clause, "OR", argv);
}

void sandbox_sqlite_where_or_i(sandbox_sqlite_where_t *where, char* clause, int argv)
{
    _sandbox_sqlite_where_add(where, clause, "OR", sandbox_utils_i_to_s(argv));
}

char* sandbox_sqlite_where_get_query(sandbox_sqlite_where_t *where)
{
    if (sandbox_sqlite_where_is_empty(where)) {
        return "";
    }

    char* query = "";
//    int length = sandbox_utils_array_size_s(where->conditions);
//    for (int i=0; i<length; i++) {
//        if (i > 0) {
//            sprintf(query, "%s %s", query, where->logicalOperators[i-1]);
//        }
//        sprintf(query, "%s (%s)", query, where->conditions[i]);
//    }
    return query;
}

int sandbox_sqlite_where_is_empty(sandbox_sqlite_where_t *where)
{
    return sandbox_utils_array_is_empty_s(where->conditions);
}

