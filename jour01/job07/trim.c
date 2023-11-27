int my_strlen(char *chain);

char *trim_begin_end(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
        j--;
    char *trimmed_str = malloc(sizeof(char) * (j - i + 2));
    int k = 0;
    while (i <= j)
    {
        trimmed_str[k] = str[i];
        i++;
        k++;
    }
    trimmed_str[k] = '\0';
    return (trimmed_str);

}