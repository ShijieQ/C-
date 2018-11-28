#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 100
char a[maxn][maxn];
void dfs(int x,int y,int m,int n)
{
    if(x < 0|| y < 0|| x > m-1|| y > n-1)
        return;
    a[x][y] = '.';
    for(int i = x-1; i <= x+1; i++)
        for(int j = y-1; j <= y+1; j++)
            if(i >=0 && j >=0 && i < m && j < n && a[i][j] == 'W')
                dfs(i,j,m,n);
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n) != EOF)
    {
        int i,j,num = 0;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                cin>>a[i][j];
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(a[i][j] == 'W')
                {
                    dfs(i,j,m,n);
                    num++;
                }
        printf("%d\n",num);
    }
}
