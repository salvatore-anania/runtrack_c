void my_putchar(char c);

void my_putstr(char *chain)
{
    int i = 0;
    while (chain[i] != '\0')
    {
        my_putchar(chain[i]);
        i++;
    }
}