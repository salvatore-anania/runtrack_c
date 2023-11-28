#include <stdlib.h>
#include <stdio.h>

void delete_str_array(char ***array)
{
    int i = 0;
    while ((*array)[i] != NULL) {
        free((*array)[i]);
        i++;
    }
    free(*array);
    *array = NULL;
}