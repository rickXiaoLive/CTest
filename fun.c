#include <stddef.h>
#include "./fun.h"

// 字符串长度
int str_length(char const *str){
    int length = 0;
    while(*str != '\0'){
        length ++;
        str++;
    }
    return length;
}

// 字符串中是否包含一个字符串 -1 为没有 >0 为包含字符串的起始位置 从字符串 0开始
int str_indexof(char *str,char const *substr){
     if(str == NULL || substr == NULL)
        return -1;

    int sreLength = str_length(str);
    int substrLength = str_length(substr);

    if( sreLength == 0 || substrLength == 0 || sreLength < substrLength)
        return -1;
    int maxOffset = sreLength-substrLength;
    int index = -1;
    for (int o = 0; o < maxOffset; ++o){
        for(int i = o,j=0 ;j<substrLength; ++i,++j){
            if((*(str+i) == *(substr+j)) && (index < 0))
                index = i;
            if(*(str+i) != *(substr+j)){
                index = -1;
                break;
            } 
        }
        if(index>=0)
            return index;
    }
    return -1;
  
}