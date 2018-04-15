#include <stdio.h>
#include <stddef.h>
int del_substr(char *str, char const *substr);
int str_length(char const *str);
int str_indexof(char *str,char const *substr);

int main(){
    char str[] = "hello del str";//只能为数组变量，要修改就不能为常量
    char *substr = "del "; 
    int res = del_substr(str,substr);
    printf("%d,%s\n",res,str);
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

//字符串长度
int str_length(char const *str){
    int length = 0;
    while(*str != '\0'){
        length ++;
        str++;
    }
    return length;
}

//字符串中是否包含一个字符串 -1 为没有 >0 为包含字符串的起始位置 从字符串 0开始
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