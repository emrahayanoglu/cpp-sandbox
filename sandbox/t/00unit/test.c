#include <picotest.h>
#include "./test.h"

int main(int argc, char **argv)
{
    subtest("lib/where.c", test_lib__where_c);

    return done_testing();
}
