#include <stdlib.h>
int my_strcmp(char const *s1, char const *s2);

char **sort(char **array)
{
    int i = 0;
    int j = 0;
    char *tmp = NULL;
    while (array[i] != NULL) {
        j = i + 1;
        while (array[j] != NULL) {
            if (my_strcmp(array[i], array[j]) > 0) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return array;
}