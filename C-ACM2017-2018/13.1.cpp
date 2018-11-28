#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[500005],b[500005],c[500005];
int main()
{
	int d,an,bn,cn;
	while(scanf("%d %d %d %d",&d,&an,&bn,&cn) != EOF)
	{
		long long int ans = 0;
		for(int i = 1; i <= an; i++)
			scanf("%d",&a[i]);
		for(int i = 1; i <= bn; i++)
			scanf("%d",&b[i]);
		for(int i = 1; i <= cn; i++)
			scanf("%d",&c[i]);
		for(int i = 1; i <= an; i++)
		{
			for(int j = 1; b[j] <= a[i] + d && j <= bn; j++)
			{
				if(a[i] - b[j] > d || b[j] - a[i] > d)
					continue;
				for(int k = 1; c[k] <= a[i] + d && k <= cn; k++)
				{
					if(a[i] - c[k] > d || c[k] - a[i] > d)
						continue;
					if(abs(c[k] - b[j]) <= d)
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
 } 
