#include<stdio.h>
#include<string.h>
int str_cmp(char* s1, char* s2){
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] < s2[i]) return -1; 
		else if(s1[i] > s2[i]) return 1;
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0') return 0;
    else if(s1[i] == '\0') return -1;
	else return 1;
}
int main(){
    char str1[] = "abc";
    char str2[] = "abd";
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("str_cmp(str1, str2)=%d\n", str_cmp(str1, str2));
    printf("str_cmp(str2, str1)=%d\n", str_cmp(str2, str1));
    printf("str_cmp(str1, str1)=%d", str_cmp(str1, str1));
    return 0;
}
