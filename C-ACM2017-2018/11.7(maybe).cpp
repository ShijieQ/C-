#include<bits/stdc++.h>
using namespace std;
int gcd(long long int a,long long int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long k,l,m,n;
		scanf("%lld %lld %lld %lld",&k,&l,&m,&n);
		long long c = gcd(n,m);
		m /= c;
		n /= c;
		double x,y;
	//	double a,b;
		x = k * sqrt((n*1.0)/m) - l;
		y = l * sqrt((n*1.0)/m) - k;
	/*	a=x;
		b=y; */
		printf("%lf %lf\n", x, y);
	}
	return 0;
}

