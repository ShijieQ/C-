#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1000005];
int num[10][1000005]={0};
int judge(int n)
{
	int ans = 1;
	do
	{
		int k = n%10;
		if(k)
			ans *= k;
		n = n/10;
	}while(n);
	if(ans/10 == 0)
		return ans;
	else
		judge(ans);
}
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= 1000000; i++)
		a[i] = judge(i);
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 1000000; j++)
			if(a[j] == i)
				num[i][j] = num[i][j-1] + 1;
			else
				num[i][j] = num[i][j-1];
	while(n--)
	{
		int l, r, k;
		int ans = 0;
		scanf("%d %d %d",&l, &r, &k);
		cout<<num[k][r] - num[k][l-1]<<endl;
	}
}
