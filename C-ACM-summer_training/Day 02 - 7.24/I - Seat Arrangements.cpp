#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
char arr[2005][2005];
int l[2005], n[2005];
int main()
{
	int x, y, k;
	cin>>x>>y>>k;
	getchar();
	int ans = 0;
	memset(l, 0, sizeof(l));
	memset(n, 0, sizeof(n));
	for(int i = 0; i < x; i++)
	{
		gets(arr[i]);
		for(int j = 0; j < y; j++)
		{
			
			if(arr[i][j] == '.')
			{
				l[i]++;
				n[j]++;
			}
			else
			{
				l[i] = 0;
				n[j] = 0;
			}
			if(l[i] >= k) 
				ans++;
			if(n[j] >= k && k != 1)
				ans++;
		}
	}	
	cout<<ans<<endl;
}
