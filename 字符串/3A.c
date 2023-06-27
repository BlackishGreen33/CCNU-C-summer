#include<stdio.h>
int str_len(char* str){
    int len = 0;
    while(str[len] != '\0') len++;
    return len;
}
int main(){
    char str[] = "hello, world!";
    int len = str_len(str);
    printf("The length of hello, world! is %d", len);
    return 0;
}
