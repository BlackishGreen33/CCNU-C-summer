#include<stdio.h>
#include<string.h>
void reverse(char *s){
    int len = strlen(s);
    char *p = s;
    char *q = s + len - 1;
    while(p < q){
        char temp = *p;
        *(p++) = *q;
        *(q--) = temp;
    }
}
void itoa(int num, char *s){
    int sign = num;
    if(sign < 0) num = -num;
    int i = 0;
    do{
        s[i++] = num % 10 + '0';
        num /= 10;
    } while(num > 0);
    if(sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main(){
    int num1 = 12345;
    int num2 = -67890;
    char str1[20];
    char str2[20];
    itoa(num1, str1);
    itoa(num2, str2);
    printf("str1 = %s\n", str1);
    printf("str2 = %s", str2);
    return 0;
}
