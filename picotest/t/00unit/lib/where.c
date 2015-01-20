#include <string.h>
#include "../test.h"
#include "../../../lib/where.c"
#include "picotest.h"

void test_lib__where_c(void)
{
    sandbox_sqlite_where_t where = sandbox_sqlite_where_init();

    {
        char* query = NULL;
        ok(sandbox_sqlite_where_is_empty(&where));
        query = sandbox_sqlite_where_get_query(&where, query);
        ok(0 == sandbox_utils_array_size_s(where.arguments));
        ok(strcmp(query, " (id = 1) "));
    }
    {
        sandbox_sqlite_where_and(&where, "id = 2");
        char* query = NULL;
        ok(!sandbox_sqlite_where_is_empty(&where));
        query = sandbox_sqlite_where_get_query(&where, query);
        ok(0 == sandbox_utils_array_size_s(where.arguments));
        ok(strcmp(query, " (id = 2) "));
    }
    {
        sandbox_sqlite_where_and_s(&where, "id = ?", "foo");
        char* query = NULL;
        ok(!sandbox_sqlite_where_is_empty(&where));
        query = sandbox_sqlite_where_get_query(&where, query);
        ok(strcmp(query, " (id = 2) AND (id = ?) "));
        ok(1 == sandbox_utils_array_size_s(where.arguments));
        ok(!strcmp("foo", where.arguments[0]));
    }
    {
        sandbox_sqlite_where_or(&where, "id = 1");
        char* query = NULL;
        ok(!sandbox_sqlite_where_is_empty(&where));
        query = sandbox_sqlite_where_get_query(&where, query);
        ok(strcmp(query, " (id = 2) AND (id = ?) OR (id = 1) "));
        ok(1 == sandbox_utils_array_size_s(where.arguments));
        ok(!strcmp("foo", where.arguments[0]));
    }
    {
        sandbox_sqlite_where_or_s(&where, "name = ?", "bar");
        char* query = NULL;
        ok(!sandbox_sqlite_where_is_empty(&where));
        query = sandbox_sqlite_where_get_query(&where, query);
        ok(strcmp(query, " (id = 2) AND (id = ?) OR (id = 1) OR (name ?)"));
        ok(2 == sandbox_utils_array_size_s(where.arguments));
        ok(!strcmp("foo", where.arguments[0]));
        ok(!strcmp("bar", where.arguments[1]));
    }
}
