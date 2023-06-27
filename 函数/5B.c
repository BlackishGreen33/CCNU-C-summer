#include<stdio.h>
#include<string.h>
void fun(char *p){
    int max_idx = 0;
    for(int i = 1; i < strlen(p); i++)
        if (p[i] > p[max_idx]) max_idx = i;
    char temp = p[max_idx];
    for(int i = max_idx; i > 0; i--) p[i] = p[i - 1];
    p[0] = temp;
}
int main(){
    char str[8];
    for(int i = 0; i < 8; i++) scanf("%c", &str[i]);
    printf("Before calling fun: %s\n", str);
    fun(str);
    printf("After calling fun: %s", str);
    return 0;
}
