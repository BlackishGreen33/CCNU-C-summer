#include<stdio.h>
enum money{
    FEN_1,
    FEN_2,
    FEN_5,
    JIAO_1,
    JIAO_2,
    JIAO_5,
    YUAN_1,
    YUAN_2,
    YUAN_5,
    YUAN_10,
    YUAN_50,
    YUAN_100
};
int main(){
    double amount;
    printf("Plz enter the amount in yuan: ");
    scanf("%lf", &amount);
    int fen_1 = 0, fen_2 = 0, fen_5 = 0;
    int jiao_1 = 0, jiao_2 = 0, jiao_5 = 0;
    int yuan_1 = 0, yuan_2 = 0, yuan_5 = 0, yuan_10 = 0, yuan_50 = 0, yuan_100 = 0;
    while(amount >= 100){
        amount -= 100;
        yuan_100++;
    }
    while(amount >= 50){
        amount -= 50;
        yuan_50++;
    }
    while(amount >= 10){
        amount -= 10;
        yuan_10++;
    }
    while(amount >= 5){
        amount -= 5;
        yuan_5++;
    }
    while(amount >= 2){
        amount -= 2;
        yuan_2++;
    }
    while(amount >= 1){
        amount -= 1;
        yuan_1++;
    }
    while(amount >= 0.5){
        amount -= 0.5;
        jiao_5++;
    }
    while(amount >= 0.2){
        amount -= 0.2;
        jiao_2++;
    }
    while(amount >= 0.1){
        amount -= 0.1;
        jiao_1++;
    }
    while(amount >= 0.05){
        amount -= 0.05;
        fen_5++;
    }
    while(amount >= 0.02){
        amount -= 0.02;
        fen_2++;
    }
    while(amount >= 0.01){
        amount -= 0.01;
        fen_1++;
    }
    printf("100 yuan: %d\n", yuan_100);
    printf("50 yuan: %d\n", yuan_50);
    printf("10 yuan: %d\n", yuan_10);
    printf("5 yuan: %d\n", yuan_5);
    printf("2 yuan: %d\n", yuan_2);
    printf("1 yuan: %d\n", yuan_1);
    printf("5 jiao: %d\n", jiao_5);
    printf("1 jiao: %d\n", jiao_1);
    printf("5 fen: %d\n", fen_5);
    printf("2 fen: %d\n", fen_2);
    printf("1 fen: %d", fen_1);
    return 0;
}
