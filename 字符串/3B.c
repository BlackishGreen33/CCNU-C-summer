#include<stdio.h>
#include<string.h>
void str_cat(char* dest, char* src){
    int i, j;
    for(i = 0; dest[i] != '\0'; i++);
    for(j = 0; src[j] != '\0'; j++) dest[i + j] = src[j];
    dest[i + j] = '\0';
}
int main(){
    char str1[] = "hello";
    char str2[] = ", world!";
    printf("%s\n", str1);
    printf("%s\n", str2);
    char result[100] = "";
    str_cat(result, str1);
    str_cat(result, str2);
    printf("%s", result);
    return 0;
}
