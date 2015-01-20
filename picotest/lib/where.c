#include <stdio.h>
#include <stdlib.h>
#include <where.h>
#include <utils.h>

static void _sandbox_sqlite_where_add(sandbox_sqlite_where_t *where, char *clause, char *logicalOperator, char *argv)
{
    if (sandbox_utils_array_size_s(where->conditions) > 0) {
        sandbox_utils_array_push_s(where->logicalOperators, logicalOperator);
    }
    if (argv != NULL) {
        sandbox_utils_array_push_s(where->arguments, argv);
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

void sandbox_sqlite_where_or(sandbox_sqlite_where_t *where, char* clause)
{
    _sandbox_sqlite_where_add(where, clause, "OR", NULL);
}

void sandbox_sqlite_where_or_s(sandbox_sqlite_where_t *where, char* clause, char* argv)
{
    _sandbox_sqlite_where_add(where, clause, "OR", argv);
}

char* sandbox_sqlite_where_get_query(sandbox_sqlite_where_t *where, char *query)
{

    if (sandbox_sqlite_where_is_empty(where)) {
        return "";
    }

    size_t retSize = 0;

    int loLength = sandbox_utils_array_size_s(where->logicalOperators);
    int loSeparatorSize = sizeof("  ");
    for (int i=0; i<loLength; i++) {
        retSize += sizeof(where->logicalOperators[i]) + loSeparatorSize;
    }

    int cLength = sandbox_utils_array_size_s(where->conditions);
    int cSeparatorSize = sizeof(" () ");
    for (int i=0; i<cLength; i++) {
        retSize += sizeof(where->conditions[i]) + cSeparatorSize;
    }

    query = realloc(query, retSize);
    for (int i=0; i<cLength; i++) {
        if (i > 0) {
            sprintf(query, "%s %s", query, where->logicalOperators[i-1]);
        }
        sprintf(query, "%s (%s)", query, where->conditions[i]);
    }
    return query;
}

int sandbox_sqlite_where_is_empty(sandbox_sqlite_where_t *where)
{
    return sandbox_utils_array_is_empty_s(where->conditions);
}

