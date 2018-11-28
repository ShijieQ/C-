#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        char a[105];
        char ans[105];
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        scanf("%s", a);
        int len = strlen(a);
        printf("Case #%d: ", t);
        if(len >= 4){
            printf("317\n");
        }
        else{
            int num = 0;
            for(int i = 0; i < len; i++){
                num *= 10;
                num += a[i]-'0';
            }
            if(num >= 317)
                printf("317\n");
            else if(num >= 311)
                printf("311\n");
            else if(num >= 173)
                printf("173\n");
            else if(num >= 137)
                printf("137\n");
            else if(num >= 131)
                printf("131\n");
            else if(num >= 113)
                printf("113\n");
            else if(num >= 73)
                printf("73\n");
            else if(num >= 71)
                printf("71\n");
            else if(num >= 53)
                printf("53\n");
            else if(num >= 37)
                printf("37\n");
            else if(num >= 31)
                printf("31\n");
            else if(num >= 23)
                printf("23\n");
            else if(num >= 17)
                printf("17\n");
            else if(num >= 13)
                printf("13\n");
            else if(num >= 11)
                printf("11\n");
            else if(num >= 7)
                printf("7\n");
            else if(num >= 5)
                printf("5\n");
            else if(num >= 3)
                printf("3\n");
            else if(num >= 2)
                printf("2\n");
        }
    }
}
