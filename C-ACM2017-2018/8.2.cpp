#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long int m,n;
	while(scanf("%lld %lld",&m,&n) != EOF && n && m)
	{
		unsigned long long int sum = 0;
		if(m < n)
		{
			long long int tem = m;
			m = n;
			n = tem;
		}
		sum = n*m*(m-1) + m*n*(n-1) + 2*n*(n-1)*(n-2)*2/3 + (m-n+1)*n*(n-1)*2;
		cout<<sum<<endl;
	}
}
