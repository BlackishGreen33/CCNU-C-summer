#include<stdio.h>
union u4{
    unsigned int i;
    unsigned char c[4];
};
int main(){
    union u4 u;
    u.i = 0x12345678;
    printf("Before conversion: %08x\n", u.i);
    printf("After conversion: ");
    for(int i = 0; i < 4; i++) printf("%c", u.c[i]);
    return 0;
}
