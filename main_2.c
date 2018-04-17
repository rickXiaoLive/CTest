#include <stdio.h>
#include <stddef.h>
#include "./fun.h"

int del_substr(char *str, char const *substr);

int main2(int argc, const char * argv[]){
    char str[] = "hello del str";//只能为数组变量，要修改就不能为常量
    char *substr = "del ";
    int res = del_substr(str,substr);
    printf("%d,%s\n",res,str);
    printf("hell ");
    return 0;
}

int del_substr(char *str,char const *substr){
    int index = str_indexof(str,substr);
    if(index<0)
        return 0;
    int strLength = str_length(str);
    int substrLength = str_length(substr);
    //删除字符串起点
    char *startIndex = str+index;
    //删除字符串终点
    char *endIndex = str+(index+substrLength);

    for(int i=(index+substrLength),j=0;i<=strLength;++i,++j){
        *(startIndex+j)=*(endIndex+j);
    }
    return 1;
}

