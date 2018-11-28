#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
char str1[110000];
char str2[110000];
int num[10000]={0};
int main()
{
    while(scanf("%s",str1) != EOF)
    {
        int k = 0;
        int flag = 0;
        int len = strlen(str1);
        strcpy(str2,str1);
        for(int i = 0,j = len-1; i < len && j >= 0; )
            if(str1[i++] == str2[j--])
                num[k]++;
            else
                k++;
        sort(num,num+k);
        printf("%d",num[k]);
    }
}
