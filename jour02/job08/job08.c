#include <stdlib.h>
#include <unistd.h>

char *trim(char *chain);
char **sort(char **chain);
int my_strlen(char *chain);

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            argv[i]=trim(argv[i]);
        }
        sort(argv);
        for(int i = 1; i < argc; i++)
        {
            write(1, argv[i], my_strlen(argv[i]));
            write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
    return (0);
}