#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int n, k;
	int a[105];
	cin>>n>>k;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	for(int i = n-1; i >= 0; i--)
	{
		if(k % a[i] == 0 && a[i] <= k)
		{
			cout<<k/a[i]<<endl;
			break;
		}
	}
}
