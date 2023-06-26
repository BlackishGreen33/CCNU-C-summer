#include<stdio.h>
int main(){
    int cock, hen, chick, count = 0;
    for(cock = 0; cock <= 20; cock++)
        for (hen = 0; hen <= 33; hen++){
            chick = 100 - cock - hen;
            if(chick % 3 == 0 && cock * 5 + hen * 3 + chick / 3 == 100)
                printf("Solution %d: %d cocks, %d hens, %d chicks\n", ++count, cock, hen, chick);
        }
    return 0;
}
