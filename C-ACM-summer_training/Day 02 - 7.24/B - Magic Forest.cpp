#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i+1; j <= n; j++)
		{
			int k = i ^ j;
			if(i + j > k && j + k > i && i + k > j && k >=1 && k <= n && k >= j)
				ans++;
		}
	}
	cout<<ans<<endl;
 } 
