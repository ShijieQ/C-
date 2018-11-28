#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
char str[1000000];
int main()
{
    char str_find[10000];
    int n;
    while(scanf("%d",&n) != EOF && n)
    {
        for(int i = n; i > 0; i--)
        {
            int judge = 1;
            int flag = 0;
            scanf("%s",str_find);
            scanf("%s",str);
/*            if(str_find[0] == str_find[strlen(str_find)-1])
                judge = 0;*/
            for(int j = 0,k = 0; j < strlen(str); j++)
            {
                if(str[j] == str_find[k])
                {
                    if(k == strlen(str_find) - 1)
                    {
                        k = 0;
                        flag++;
                    }
                        k++;
                }
                else
                    k = 0;
            }
            printf("%d\n",flag);
            flag = 0;
        }
    }
    return 0;
}
