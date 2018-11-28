//hdu 1695
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int m,int n)
{
	return (m == 0)?n:gcd(n%m,m);
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num = 0;
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		for(int i = a; i <= b; i++)
			for(int j = c; j <= d; j++)
				if(gcd(i,j) == k)
				{
					cout<<i<<" "<<j<<endl;
					num++;
				}
		cout<<num<<endl;
	}
	return 0;
} 
