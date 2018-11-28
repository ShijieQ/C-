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
	int dp[2005];
	thing *things = new thing[n+1];
	for(int i = 1; i <= n; i++)
		cin>>things[i].t>>things[i].d>>things[i].p;
	sort(things+1,things+n+1,cmp);
	for(int i = 0; i <= 2004; i++)
		dp[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = things[i].d - 1; j >= things[i].t; j--)
			dp[j] = max(dp[j],dp[j - things[i].t] + things[i].p);
		for(int j = things[i].d; j < things[n].d; j++)
			dp[j] = max(dp[j],dp[things[i].d-1]);
	}
	cout<<dp[things[n].d-1]<<endl;
	return 0;
}	
