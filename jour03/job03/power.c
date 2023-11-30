int power(int base, int exp){
    int res = 1;
    while(exp > 0){
        res = res * base;
        exp--;
    }
    return res;
}