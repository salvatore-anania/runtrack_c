#include <stdlib.h>

int my_strlen(char *chain);
char my_strcpy(char *dest, char const *src);


char **array_clone(char **str, int size) {
    int len = 0;
    for (len = 0; str[len] != NULL; len++) {
    }
    if(len < size) {
        size = len;
    }
    char **clone = malloc(sizeof(char *) * size+1);
    for (int i = 0; i < size; i++) {
        clone[i] = malloc(sizeof(char) * (my_strlen(str[i])));
        my_strcpy(clone[i], str[i]);
    }
    clone[size] = NULL;
    return clone;
}