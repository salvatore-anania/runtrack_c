#include <stdlib.h>

void my_putstr(char *chain);
int my_putchar(char c);
void str_to_upper(char *chain){
    int i = 0;
    while (chain[i] != '\0')
    {
        if (chain[i] >= 'a' && chain[i] <= 'z'){
            chain[i] -= 32;
        }
        i++;
    }

}

void str_to_lower(char *chain){
    int i = 0;
    while (chain[i] != '\0')
    {
        if (chain[i] >= 'A' && chain[i] <= 'Z'){
            chain[i] += 32;
        }
        i++;
    }

}

void func_to_array(char **array, void (*func)(char *))
{
    int i = 0;
    while (array[i] != NULL) {
        func(array[i]);
        i++;
    }
}