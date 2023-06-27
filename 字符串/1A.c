#include<stdio.h>
int str_to_int(char* str){
    int num = 0;
    while (*str != '\0'){
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}
int main(){
    char str[4];
    for(int i = 0; i < 4; i++) scanf("%c", &str[i]);
    int num = str_to_int(str);
    printf("%d", num);
    return 0;
}
