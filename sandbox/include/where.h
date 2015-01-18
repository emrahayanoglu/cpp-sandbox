#ifndef sandbox_sqlite_where_h
#define sandbox_sqlite_where_h

typedef struct {
    char* conditions[16];
    char* values[16];
    char* logicalOperators[15];
} sandbox_sqlite_where_t;

sandbox_sqlite_where_t sandbox_sqlite_where_init();

int sandbox_sqlite_where_is_empty(sandbox_sqlite_where_t *where);

void sandbox_sqlite_where_and(sandbox_sqlite_where_t *where, char *clause);

void sandbox_sqlite_where_and_s(sandbox_sqlite_where_t *where, char *clause, char *argv);

void sandbox_sqlite_where_and_i(sandbox_sqlite_where_t *where, char *clause, int argv);

void sandbox_sqlite_where_or(sandbox_sqlite_where_t *where, char* clause);

void sandbox_sqlite_where_or_s(sandbox_sqlite_where_t *where, char* clause, char* argv);

void sandbox_sqlite_where_or_i(sandbox_sqlite_where_t *where, char* clause, int argv);

void sandbox_sqlite_where_get_arguments(sandbox_sqlite_where_t *where);

char* sandbox_sqlite_where_get_query(sandbox_sqlite_where_t *where);

#endif
