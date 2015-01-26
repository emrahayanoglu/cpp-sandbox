#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sandbox_utils_array_push_s(char *array[], char *value) {
    int length = sizeof(&array);
    int i = 0;
    for (; i < length; i++) {
        if (array[i] == NULL) {
            break;
        }
    }
    array[i] = value;
}

int sandbox_utils_array_size_s(char *array[]) {
    int length = sizeof(&array);
    int i = 0;
    for (; i < length; i++) {
        if (array[i] == NULL) {
            break;
        }
    }
    return i;
}

char *sandbox_utils_array_join_s(char *array[], char *string) {
    int length = sandbox_utils_array_size_s(array);
    size_t size = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == NULL) {
            break;
        }
        size += strlen(array[i]);
    }
    realloc(string, size);
    for (int i = 0; i < length; i++) {
        if (array[i] == NULL) {
            break;
        }
        strcat(string, array[i]);
    }
    return string;
}

int sandbox_utils_array_is_empty_s(char *array[]) {
    int length = sizeof(&array);
    int i = 0;
    for (; i < length; i++) {
        if (array[i] == NULL) {
            break;
        }
    }
    return i <= 0;
}
