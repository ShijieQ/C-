#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
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
		long long x,y;
		x = k * sqrtl(n/m) - l;
		y = l * sqrtl(n/m) - k;
		printf("%lld %lld",x,y);
	}
 }

