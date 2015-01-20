#include <stdio.h>
#include "hello.h"
#include "where.h"

int main() {
    printf("%s\n", sandbox_hello_world());

    sandbox_sqlite_where_t where = sandbox_sqlite_where_init();

    //TODO: use `picotest`
    sandbox_sqlite_where_and(&where, "id = ?");
    sandbox_sqlite_where_and_s(&where, "id = ?", "a");
    sandbox_sqlite_where_and_s(&where, "id = ?", "b");
    sandbox_sqlite_where_and_i(&where, "id = ?", 1);
    sandbox_sqlite_where_or(&where, "id = ?");
    sandbox_sqlite_where_or_s(&where, "id = ?", "a");
    sandbox_sqlite_where_or_s(&where, "id = ?", "b");
    sandbox_sqlite_where_or_i(&where, "id = ?", 1);
    char* query = NULL; query = sandbox_sqlite_where_get_query(&where, query);
    if (sandbox_sqlite_where_is_empty(&where)) {
        printf("query is empty\n");
    } else {
        printf("query: %s\n", query);
    }

    return 0;
}