#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
/*
    寻找满足UcU格式的名字。
                        */
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        char ch[10];
        char name[10][100];
        for(int j = 0;j < 3;j++)
        {
            scanf("%s",name[j]);
            ch[j] = name[j][0];
        }
        if(ch[0] == ch[2]&&ch[1] == 'c')
        {
           printf("%s %s %s\n",name[0],name[1],name[2]);
        }
    }
    return 0;
}
