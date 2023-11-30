#include <unistd.h>
int my_atoi(const char *str);
char *my_itoa(int num);
int my_strlen(char *str);

int main(int argc, char const *argv[])
{
    char *result;
    if (argc != 2){
        return 0;
    }
    int fact = my_atoi(argv[1]);
    int i = 0;
    int res = 0;
    while(i <+ fact){
        i++;
        res += i;
    }
    result = my_itoa(res);
    write(1, result, my_strlen(result));
    return 0;
}