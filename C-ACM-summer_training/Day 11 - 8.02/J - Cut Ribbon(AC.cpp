#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
const int maxn=1e5+7;
const int INF=1e7+7;
int n;
int a[3];
int dp[4005];
int main()
{
    scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
    for(int i=1;i<=n;i++)
            dp[i]=-INF;
    dp[0]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
         for(int j=0;j<3;j++)
            if(i>=a[j]){
                dp[i] = max(dp[i],dp[i-a[j]]+1);
                for(int i = 0; i <= n; i++){
                	cout<<dp[i]<<" ";
				}
				cout<<endl;
			}
    printf("%d\n",dp[n]);
	return 0;
}
