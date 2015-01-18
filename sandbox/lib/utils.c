#include <stdio.h>

void sandbox_utils_array_push_s(char *array[], char* value)
{
    int length = sizeof(&array);
    int i = 0;
    for (; i<length; i++) {
        if (array[i] == NULL) {
            break;
        }
    }
    array[i] = value;
}

int sandbox_utils_array_size_s(char *array[])
{
    int length = sizeof(&array);
    int i = 0;
    for (; i<length; i++) {
        if (array[i] == NULL) {
            break;
        }
    }
    return i;
}

int sandbox_utils_array_is_empty_s(char *array[])
{
    int length = sizeof(&array);
    int i = 0;
    for (; i<length; i++) {
        if (array[i] == NULL) {
            break;
        }
    }
    return i <= 0;
}

char* sandbox_utils_i_to_s(int value)
{
    char* ret;
    sprintf(&ret, "%d", value);
    return ret;
}

