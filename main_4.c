#include <stdio.h>

int ascii2integer(char *string){
    int res = 0;
    while(*string != '\0'){
        int tmp = *string - 48 ;
        if(tmp >= 0 || tmp <= 9){
            res *= 10;
            res += tmp;
        }else{
            return 0;
        }
        string++;
    }
    return res;
}
void main4(){
    int res = ascii2integer("123243");
    printf("%d\n",res);
}
