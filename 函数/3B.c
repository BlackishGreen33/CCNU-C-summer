#include<stdio.h>
void fun(char *s, int *t){
    *t = 0;
    while (*s){
        if(*s >= '0' && *s <= '9') (*t)++;
        s++;
    }
}
int main(){
    char s[19];
    for(int i = 0; i < 19; i++) scanf("%c", &s[i]);
    int t;
    fun(s, &t);
    printf("The number of digit characters in the string is: %d", t);
    return 0;
}
