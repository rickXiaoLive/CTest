#include <stdio.h>
#include <stddef.h>
#include "./fun.h"

void daoxu(char *str);

void main3(){
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

