#include<stdio.h>
#include<string.h>
#include<ctype.h>
void fun(char *tt, int pp[]){
    int i, len;
    len = strlen(tt);
    for(i = 0; i < len; i++)
        if(isalpha(tt[i])) pp[tolower(tt[i]) - 'a']++;
}
int main(){
    char str[] = "abcdefgabcdeabc";
    printf("%s\n", str);
    int count[26] = {0};
    fun(str, count);
    for (int i = 0; i < 26; i++) printf("%d ", count[i]);
    return 0;
}
