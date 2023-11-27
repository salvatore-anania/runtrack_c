#include <stdlib.h>
int my_strlen(char *chain);

char *my_strdup(char *src)
{
    int i = 0;
    char *dest;
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}