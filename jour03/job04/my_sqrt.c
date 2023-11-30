int my_sqrt(int num){
    int i = 0;
    int res = 0;
    while(res <= num){
        i++;
        res = i * i;
    }
    return i-1;
}