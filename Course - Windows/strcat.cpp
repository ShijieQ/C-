#include<stdio.h>
#include<stdlib.h>

const int maxn = 1e6+10;
char *strcat(char *str1, char *str2){
    int len1 = 0, len2 = 0;
    while(str1[len1] != '\0'){
        len1++;
    }
    while(str2[len2] != '\0'){
        len2++;
    }
    char *ans = (char *)malloc(len1 + len2 + 1);
    for(int i = 0; i < len1; i++){
        ans[i] = str1[i];
    }
    for(int i = len2, j = 0; j < len2; j++,i++){
        ans[i] = str2[j];
    }
    ans[len1+len2] = '\0';
    return ans;
}

int main(){
    char str1[maxn], str2[maxn];
    /*
    gets(str1);
    gets(str2);
    */
    scanf("%s%s", str1, str2);
    char *ans = strcat(str1, str2);
    printf("%s", ans);
    return 0;
}