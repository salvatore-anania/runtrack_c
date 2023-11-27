#include <stdlib.h>

int my_strlen(char *chain);

char **split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len = my_strlen(str);
    char **tab = malloc(sizeof(char *) * (len + 1));
    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        j = i;
        while (str[j] != ' ' && str[j] != '\t' && str[j] != '\n' && str[j] != '\0')
            j++;
        if (j > i)
        {
            tab[k] = malloc(sizeof(char) * (j - i + 1));
            int l = 0;
            while (i < j)
            {
                tab[k][l] = str[i];
                i++;
                l++;
            }
            tab[k][l] = '\0';
            k++;
        }
    }
    tab[j] = NULL;
    return (tab);
}
