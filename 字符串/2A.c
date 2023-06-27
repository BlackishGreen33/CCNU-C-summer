#include<stdio.h>
void int_to_str(int num, char* str){
    if(num == 0){
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    int sign = num < 0 ? -1 : 1;
    int i = 0;
    while(num != 0){
        int digit = num % 10;
        str[i] = digit < 0 ? -digit + '0' : digit + '0';
        num /= 10;
        i++;
    }
    if(sign < 0){
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    for(int j = 0; j < i / 2; j++){
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}
int main(){
    int num;
    scanf("%d", &num);
    char str[20];
    int_to_str(num, str);
    printf("%s", str);
    return 0;
}
