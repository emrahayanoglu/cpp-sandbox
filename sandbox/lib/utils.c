#include <stdio.h>
#include <string.h>

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


int sandbox_utils_array_join_s(char *array[])
{
    int length = sandbox_utils_array_size_s(array);
    long size = 0;
    for (int i=0; i<length; i++) {
        if (array[i] == NULL) {
            break;
        }
        size += strlen(array[i]);
    }
    char ret[size];
    for (int i=0; i<length; i++) {
        if (array[i] == NULL) {
            break;
        }
        strcat(ret, array[i]);
    }
    return ret;
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

