#include<stdio.h>
void str_copy(char* s1, char* s2){
    int i;
    for(i = 0; s1[i] != '\0'; i++) s2[i] = s1[i];
    s2[i] = '\0';
}
int main(){
    char str1[] = "hello, world!";
    char str2[100];
    printf("str1=%s\n", str1);
    printf("str2=%s\n\n", str2);
    str_copy(str1, str2);
    printf("str1=%s\n", str1);
    printf("str2=%s", str2);
    return 0;
}
