#include<bits/stdc++.h>
typedef long long ll ; 

using namespace std;

const double EXP = 1e-6;
const int maxn = 1e6+10;
int st[1010];
int main(){
	memset(st,0,sizeof(st));
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		st[x]++;
	}
	int sum[1010];
	sum[0]=0;
	for(int i=1;i<=1005;i++){
		sum[i]=sum[i-1]+st[i];
	}
	int t,ans=0;
	scanf("%d",&t);
	for(int i=t+1;i<=1005;i++){
		ans=max(ans,sum[i]-sum[i-t-1]);
	}
	printf("%d\n",ans);
	return 0;
}
