#include <stdio.h>
#include <stddef.h>

void daoxu(char *str);

//字符串长度
int str_length(char const *str){
    int length = 0;
    while(*str != '\0'){
        length ++;
        str++;
    }
    return length;
}

int main(){
    char str[] = "hello del str";

    daoxu(str);
    printf("%s\n",str);
}

void daoxu(char *str){
    int length = str_length(str);
    char t;
    char *endAddr = str+length-1;
    for(char *p = str;p<endAddr;++p,--endAddr){
        t = *p;
        *p=*endAddr;
        *endAddr = t;
    }
}

