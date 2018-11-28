#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long int x[100],y[100];
long long int gcd(long long int a,long long int b)
{
	long long int m = a % b;
	if(m) gcd(b,m);
	else return b;
}
int main()
{
	int n;
	while(scanf("%lld",&n) != EOF)
	{
		int num;
		for(int i = 0; i < n; i++)
			scanf("%lld/%lld",&x[i],&y[i]);
		for(int i = 0; i < n-1; i++)
		{
			long long int flg = y[i]*y[i+1]/gcd(y[i],y[i+1]);
			x[i+1] = x[i]*(flg/y[i]) + x[i+1]*(flg/y[i+1]);
			y[i+1] = flg;
			long long int tem = gcd(x[i+1],y[i+1]);
			x[i+1] /= tem;
			y[i+1] /= tem;
		}
		num = x[n-1] / y[n-1];
		long long int temp = x[n-1]-num*y[n-1];
		if(!num)
			if(x[n-1])
				printf("%d/%d\n",x[n-1],y[n-1]);
			else
				printf("0\n");
		else if(num > 0 && temp)
			printf("%d %d/%d\n",num,temp,y[n-1]);
			else
				printf("%d\n",num);
	}
	return 0;
} 
