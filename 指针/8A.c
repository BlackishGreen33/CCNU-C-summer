#include<stdio.h>
#include<string.h>
void copy_string(char *src, char *dest, int m){
    int len = strlen(src);
    for(int i = m, j = 0; i < len; i++, j++)
        *(dest + j) = *(src + i);
    *(dest + len - m) = '\0';
}
int main(){
    char str1[100];
    char str2[100];
    int m;
    printf("Enter a string: ");
    scanf("%s", str1);
    printf("Enter the starting position: ");
    scanf("%d", &m);
    copy_string(str1, str2, m);
    printf("The copied string is: %s", str2);
    return 0;
}
