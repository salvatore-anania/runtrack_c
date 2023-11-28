#include <stdlib.h>
#include <unistd.h>

void str_to_lower(char *chain);
int my_strlen(char *chain);

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            str_to_lower(argv[i]);
            write(1, argv[i], my_strlen(argv[i]));
            write(1, "\n", 1);
        }
    }
    return (0);
}