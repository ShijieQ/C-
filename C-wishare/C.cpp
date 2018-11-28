#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int max1;
		int sum = 0;
		int N,b1 = 0;
		int dp[10005];
		int a[25],b[25];
		int c[105]; 
		cin>>N;
		int k = 1;
		for(int i = 1; i <= N; i++)
		{
			cin>>a[i]>>b[i];
			b1 += b[i];
			sum += a[i]*b[i];
		}
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= b[i]; j++)
				c[k++] = a[i];
		for(int i = 0; i <= sum; i++)
			dp[i] = 0;
		for(int i = 1; i <= b1; i++)
			for(int j = sum/2; j >= c[i]; j--)
				dp[j] = max(dp[j],dp[j - c[i]]+c[i]);
		cout<<sum - dp[sum/2]<<endl;
	}
}
