int char_is_digit(char c);

int str_is_digit(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (char_is_digit(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
