#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char **arr);
int main(){
    char *arr[3];
    printf("Plz enter 3 strings:\n");
    for(int i = 0; i < 3; i++){
        arr[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", arr[i]);
    }
    sort(arr);
    printf("The strings in ascending order are:\n");
    for(int i = 0; i < 3; i++) printf("%s\n", arr[i]);
    for(int i = 0; i < 3; i++) free(arr[i]);
    return 0;
}
void sort(char **arr){
    char *temp;
    for(int i = 0; i < 2; i++)
        for(int j = i+1; j < 3; j++)
            if(strcmp(arr[i], arr[j]) > 0){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
