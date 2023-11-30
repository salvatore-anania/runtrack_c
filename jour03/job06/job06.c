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
    int base = my_atoi(argv[1]);
    // do the fibonacci of base
    int i = 0;
    int res = 0;
    int prev = 0;
    int curr = 1;
    while(i < base){
        i++;
        res = prev + curr;
        prev = curr;
        curr = res;
    }
    result = my_itoa(res);
    write(1, result, my_strlen(result));
    return 0;
}