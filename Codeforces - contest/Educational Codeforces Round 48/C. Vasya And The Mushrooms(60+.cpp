#include <cstdio>
#include <iostream>
#include <algorithm>
#define gt(x) x = read()
typedef unsigned long long ull;
const int mxn = 3e5+7;
using namespace std;
int n,a[mxn],b[mxn];
ull us[mxn][2],cir[mxn][2],sum[mxn],ans;
inline int read(int out = 0)
{
	char c;
	while((c=getchar()) < 48 || c > 57);
	while(c >= 48 && c <= 57) out=out*10+c-48,c=getchar();
	return out;
}
int main()
{
	gt(n);
	for(int i = 1;i <= n;++i) gt(a[i]);a[1] = 0;
	for(int i = 1;i <= n;++i) gt(b[i]);
	for(int i = 1,las;i <= n;++i)
	{
		if(i&1)
		{
			us[i][0] = us[i-1][0]+(ull)a[i]*(2*i-2);
			us[i][1] = us[i][0]+(ull)b[i]*(2*i-1);
			
		}else{
			us[i][1] = us[i-1][1]+(ull)b[i]*(2*i-2);
			us[i][0] = us[i][1]+(ull)a[i]*(2*i-1);
		}
		cir[i][0]+=(ull)a[i]*(i-1)+(ull)b[i]*(n+n-i),cir[i+1][0] += cir[i][0];
		cir[i][1]+=(ull)b[i]*i+(ull)a[i]*(n+n-i+1),cir[i+1][1] += cir[i][1];
		sum[i] =sum[i-1]+a[i]+b[i];
	}
	for(int i = 1;i <= n+1;++i)
	{
		if(i&1) ans = max(ans,us[i-1][0]+cir[n][0]-cir[i-1][0]+(sum[n]-sum[i-1])*(i-1));
		else ans = max(ans,us[i-1][1]+cir[n][1]-cir[i-1][1]+(sum[n]-sum[i-1])*(i-2));
	}
	ans = max(ans,cir[n][0]);
	ans = max(ans,cir[n][1]);
	cout<<ans;
	return 0;
}

