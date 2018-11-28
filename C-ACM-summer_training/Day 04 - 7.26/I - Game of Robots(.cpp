/*
	i & flag换成long long 也能a。。
	*/ 
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n, k;
	cin>>n>>k;
	int a[100005];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	double flag = 0;
	double sum = 0;
	for(double i = 1; i <= n; i++)
	{
		sum = i*(i+1)/2;
		if(sum >= k)
		{
			flag = i;
			break;
		}
	}
	sum = (flag-1)*flag/2;
	cout<<a[int(k-sum-1)]<<endl;
}
