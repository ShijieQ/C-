#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	float fp[10005];
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF && (n || m))
	{
		int w[10005];
		float v[10005];
		for(int i = 0; i <= n; i++)
			fp[i] = 1.0;  
		for(int i = 1; i <= m; i++)
			cin>>w[i]>>v[i];
		for(int i = 1; i <= m; i++)
			for(int j = n; j >= w[i]; j--)
				fp[j] = min(fp[j],fp[j - w[i]]*(1 - v[i]));
		printf("%.1f%%\n",100-fp[n]*100);
	}
	return 0;
}
