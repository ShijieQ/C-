#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct thing
{
	int t;
	int d;
	int p;
}thing;

bool cmp(struct thing a,struct thing b)
{
	if(a.d < b.d)
		return true;
	else return false;
}
 
int main()
{
	int n;
	cin>>n;
	int max1 = 0;
	int dp[105][2005]; 
	thing *things = new thing[n+1];
	for(int i = 1; i <= n; i++)
		cin>>things[i].t>>things[i].d>>things[i].p;
	sort(things+1,things+n+1,cmp);
	max1 = things[n].d;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= 2000; j++)
			dp[i][j] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= things[i].t; j++)
			dp[i][j] = dp[i-1][j];
		for(int j = things[i].t; j <= things[i].d-1; j++)
			dp[i][j] = max(dp[i-1][j],dp[i-1][j - things[i].t] + things[i].p);
		for(int j = things[i].d; j <= things[n].d; j++)
			dp[i][j] = max(dp[i][j],dp[i][things[i].d-1]);
	}
	cout<<dp[n][things[n].d-1]<<endl;
} 
