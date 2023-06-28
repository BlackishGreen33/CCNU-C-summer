#include<stdio.h>
union u2{
    unsigned short s;
    unsigned char c[2];
};
int main(){
    union u2 u;
    u.s = 0x1234;
    printf("Before conversion: %04x\n", u.s);
    unsigned char temp = u.c[0];
    u.c[0] = u.c[1];
    u.c[1] = temp;
    printf("After conversion: %04x", u.s);
    return 0;
}
