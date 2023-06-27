#include<stdio.h>
#include<string.h>
void str_shift(char* str, int m){
    int len = strlen(str);
    if(m >= len) return;
    char temp[m];
    memcpy(temp, str, m);
    memmove(str, str + m, len - m);
    memcpy(str + len - m, temp, m);
}
int main(){
    char str[] = "ABCDEFGHIJK";
    printf("%s\n", str);
    int m = 3;
    str_shift(str, m);
    printf("%s", str);
    return 0;
}
