#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int maxn = 1e6+5;
int n,pai[maxn];
int main()
{
	while(~scanf("%d",&n))
	{
		int x;
		memset(pai,0,sizeof(pai));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&x);
			pai[x]++;
		}
		ll flag = 0;
		for(int i = 1; i <= n; i++)
		{
			flag += pai[i]/2;
			pai[i] %= 2;
			if(i + 2 <= n && pai[i] && pai[i+1] % 2 && pai[i+2])
			{
				flag++;
				pai[i]--;
				pai[i+1]--;
				pai[i+2]--;
			}
		}
		printf("%d",&flag);
	}
	return 0;
}

