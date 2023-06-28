#include<stdio.h>
#include<string.h>
char *insert(char *s1, char *s2, int n){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i = len1; i >= n; i--)
        *(s1 + i + len2) = *(s1 + i);
    for(int i = 0; i < len2; i++)
        *(s1 + n + i) = *(s2 + i);
    return s1;
}
int main(){
    char str1[100];
    char str2[100];
    int n;
    printf("Enter a string: ");
    scanf("%s", str1);
    printf("Enter another string: ");
    scanf("%s", str2);
    printf("Enter the position to insert: ");
    scanf("%d", &n);
    insert(str1, str2, n);
    printf("The modified string is: %s", str1);
    return 0;
}
