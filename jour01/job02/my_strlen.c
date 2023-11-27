int my_strlen(char *chain)
{
    int i = 0;
    while (chain[i] != '\0')
    {
        i++;
    }
    return (i);
}