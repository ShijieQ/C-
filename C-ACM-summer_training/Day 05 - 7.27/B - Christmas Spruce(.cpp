#include<bits/stdc++.h>
#define N 1005
using namespace std;
int a[N],f[N],sum[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[a[i]]++;
    }
    for(int i=2;i<=n;i++)
        if(!sum[i])f[a[i]]++;
    for(int i=1;i<=n;i++)
        if(sum[i]&&f[i]<3)
        {
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}
