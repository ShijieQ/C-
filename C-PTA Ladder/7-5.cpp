#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int fun(int i)
{
	static int sum = 0;
	int b = 1;
	for(int j = 1; j <= i; j++)
		b *= j;
	sum += b;
	return sum;
}
int main()
{
	int n,sum;
	cin>>n;
	for(int i = 1; i <= n; i++)
		sum = fun(i);
	cout<<sum<<endl;
	return 0;
}
