#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = int(1e6)+100;
ll a[maxn],b[maxn];
ll sum[maxn],suma[maxn],sumb[maxn],sumc[maxn];
int n;
void pre()
{
	for(ll i=n;i>=1;i--) sum[i]=sum[i+1]+a[i]+b[i];
	for(ll i=n,j=n;i>=1;i--,j++) suma[i]=suma[i+1]+(i-1)*a[i]+j*b[i];
	for(ll i=n,j=n+1;i>=2;i--,j++) sumb[i]=sumb[i+1]+i*b[i]+j*a[i];
	sumb[1]=sumb[2]+b[1];
	ll tol=0,ret=0;
	for(ll i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			ret+=tol*a[i]; tol++;
			ret+=tol*b[i]; tol++;
			sumc[i]=ret;
		}
		else
		{
			ret+=tol*b[i]; tol++;
			ret+=tol*a[i]; tol++;
			sumc[i]=ret;
		}
	}
}
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)cin>>b[i];
	pre();ll ans=0;
	for(ll i=0;i<=n;i++)
	{
		if(i%2==0)ans=max(ans,sumc[i]+suma[i+1]+i*sum[i+1]);
		else ans=max(ans,sumc[i]+sumb[i+1]+(i-1)*sum[i+1]);
	}
	cout<<ans<<endl;
}
