#include<stdio.h>
int atoi(char *s){
    int sign = 1;
    int num = 0;
    if(*s == '-'){
        sign = -1;
        s++;
    }
    while(*s != '\0'){
        num = num * 10 + (*s - '0');
        s++;
    }
    return num * sign;
}
int main(){
    char str1[] = "12345";
    char str2[] = "-67890";
    int num1 = atoi(str1);
    int num2 = atoi(str2);
    printf("num1 = %d\n", num1);
    printf("num2 = %d", num2);
    return 0;
}
