#include<stdio.h>
#include<algorithm>
using namespace std;
int stone[500005];
int n,m,l;
bool judge(int len)
{
    int i;
    int now=0;
    int left,right;
    for(i=1;i<m;i++)
    {
        left=1;
        right=n;
        now=now+len;
        while(true)
        {
            if(left==right)
            {
                if(stone[left]>now){now=stone[left-1];}
                else now=stone[left];
                break;
            }
            int mid=(left+right)/2;
            if(stone[mid]<now)left=mid+1;
            else right=mid;
        }
        //printf("%d ",now);
    }
    if(now+len>=l)return true;
    else return false;
}
int main()
{
    int L,i,R;
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
    stone[0]=0;L=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&stone[i]);
    }
    sort(stone+1,stone+n+1);
    R=l;
    L=l/m-1;
    while(true)
    {
        //printf("%d %d\n",L,R);
        if(L==R)break;
        int mid=(L+R)/2;
        if(judge(mid))R=mid;
        else L=mid+1;

    }
    printf("%d\n",L);
    }
    return 0;
}
