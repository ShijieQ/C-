#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e5 + 5;
ll a[maxn],b[maxn];
ll sum[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++)cin>>a[i];
    for(int i =1;i<=n;i++)cin>>b[i];
    ll s1 = 0,s2 = 0;
    for(int i =1;i<=n;i++)
    {
        sum[i] = a[i] + b[i];
    }
    for(int i = n;i>=1;i--)
    {
        sum[i] += sum[i+1];
    }
    for(int i =1;i<=n;i++)
    {
        s1 += (ll)a[i]*(i-1);
        s2 += (ll)b[i]*(i-1);
    }
    for(int i = 1;i<=n;i++)
    {
        s1 += (2*n - i)*b[i];
        s2 += (2*n - i)*a[i];
    }
    ll ans = 0,now = 0;
    for(int i =1;i<=n;i++)
    {
        if(i & 1)
        {
            ans = max(ans,s1+sum[i]*(i-1)+now);
            now += 2*(i-1)*a[i] + (2*(i-1)+1)*b[i];
        }
        else
        {
            ans = max(ans,s2 + sum[i]*(i-1) + now);
            now += 2*(i-1)*b[i] + (2*(i-1)+1)*a[i];
        }
        s1 -= (i-1)*a[i] +(2*n - i)*b[i];
        s2 -= ((i-1)*b[i] +(2*n - i)*a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
