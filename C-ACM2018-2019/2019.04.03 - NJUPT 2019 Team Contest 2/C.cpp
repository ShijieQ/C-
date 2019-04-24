#include<iostream>
#include<cstdio>
using namespace std;
bool jud[3000][3000]={false};
int cnt=0;
int x1,x2,y1,y2;
void search1(int x,int y)
{
    if(y>=y2&&x>=x2)
        return;
    else if((y-y1)*(x2-x1)>(y2-y1)*(x-x1))
        search1(x+1,y-1);
    else if((y-y1)*(x2-x1)==(y2-y1)*(x-x1))
        search1(x+1,y);
    else if((y-y1)*(x2-x1)<(y2-y1)*(x-x1))
    {
        if(!jud[x][y])
        {
            jud[x][y]=true;
            cnt++;
        }
        search1(x,y+1);
    }
}
void search2(int x,int y)
{
    if(y<=y2&&x>=x2)
        return;
    else if((y-y1)*(x2-x1)>(y2-y1)*(x-x1))
        search2(x-1,y-1);
    else if((y-y1)*(x2-x1)==(y2-y1)*(x-x1))
        search2(x,y-1);
    else if((y-y1)*(x2-x1)<(y2-y1)*(x-x1))
    {
        if(!jud[x+1][y])
        {
            jud[x+1][y]=true;
            cnt++;
        }
        search2(x+1,y);
    }
}
void solve()
{
    if(x1>x2)
    {
        swap(x1,x2);
        swap(y1,y2);
    }
    if(y1<y2)
        search1(x1,y1);
    else
        search2(x1,y1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1==x2||y1==y2)
            continue;
        solve();
    }
    printf("%d\n",cnt);
}