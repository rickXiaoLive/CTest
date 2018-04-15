#include <stdio.h>
#include <stddef.h>
char const *find_char(char const *source,char const *chars);

int main(){
    char *source = "sadfgasdf";
    char *chars = "ajnadlf"; 
    char const *res = find_char(source,chars);
    printf("%c\n",*res);
}

char const *find_char(char const *source,char const *chars){
    char *res;
    res = NULL;
    if(source == NULL || chars == NULL)
        return res;
    if(*source == '\0' || *chars == '\0')
        return res;
    for(;chars!='\0';chars++ ){
        for(;*source!='\0';source++ ){
            if(*chars == *source){
                 return source;
            }
        }
    }
    return res;
}