#include<iostream>
#include<algorithm>
using namespace std;
int dp[105][10005];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int N,sum = 0,b1 = 0,max1;
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
		for(int i = 0; i <= 104; i++)
			for(int j = 0; j <= 10004; j++)
				dp[i][j] = 0;
		for(int i = 1; i <= b1; i++)
			for(int j = 1; j <= sum/2; j++)
			{
				if(j >= c[i])
					dp[i][j] = max(dp[i-1][j],dp[i-1][j - c[i]] + c[i]);
				else
					dp[i][j] = dp[i-1][j];
			}

		cout<<sum - dp[b1][sum/2]<<endl;
	}
	return 0;
}
