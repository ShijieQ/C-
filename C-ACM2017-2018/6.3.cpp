#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int m,int n)
{
	return (m == 0)?n:gcd(n%m,m);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int num = 0;
		int n,m;
		cin>>n>>m;
		for(int i = 1; i <= n; i++)
		{
			if(gcd(i,n) >= m)
				num++;
		}
		cout<<num<<endl;
	}
	return 0;
}
