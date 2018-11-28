#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int m,n;
	long long int j,o;
	while(scanf("%d%d",&m,&n) != EOF)
	{
		if(m > n)
		{
			int tem;
			tem = m;
			m = n;
			n = tem;
			
		}
		j = 0; o = 0;
		for(int i = m; i <= n; i++)
			if(i%2)
				j += i*i*i;
			else
				o += i*i;
		cout<<o<<" "<<j<<endl;
	}
	return 0;
}
