#include<stdio.h>
int main(){
    char str[] = "Hello, world!";
    char *ptr = str;
    int interval = 2;
    printf("The original string is: %s\n", str);
    printf("Output with interval %d: ", interval);
    while(*ptr != '\0'){
        printf("%c", *ptr);
        ptr += interval;
    }
    return 0;
}
