#include<stdio.h>
#include<string.h>
void revstr(char* string){
    int len = strlen(string);
    for(int i = 0; i < len / 2; i++){
        char temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    }
}
int main(){
    char str[] = "Hello, world!";
    printf("Before: %s\n", str);
    revstr(str);
    printf("After: %s", str);
    return 0;
}
