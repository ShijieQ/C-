#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
int n,prime[N],tot,ans;
bool vis[N];
void pre()
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<=n;j++)
        {
            vis[i*prime[j]]=1;
            if(!(i%prime[j]))break;
        }
    }
}
int main()
{
    scanf("%d",&n);
    pre();
    for(int l=1,r=tot;l<=r;r--)
    {
        ans++;
        int now=l,sum=prime[r];
        while(l<r&&sum*prime[l]<=n)
        sum*=prime[l++];
    }
    printf("%d\n",ans);
}