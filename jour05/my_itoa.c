#include <stdio.h>
#include <stdlib.h>
char *my_itoa(int num){

    char *str;
    int i = 0;
    int sign = 1;
    int len = 0;
    int temp = num;
    if(num < 0){
        temp = -num;
        sign = -1;
        len+=1;
    }
    while(temp != 0){
        len+=1;
        temp = temp / 10;
    }
    str = malloc(sizeof(char) * (len + 1));
    for(i=len; i>0; i-=1){
        str[i-1] = (num % 10)*sign + '0';
        num = num / 10;
    }
    str[len] = '\0';
    if(sign == -1){
        str[0] = '-';       
    }
    return str;
}