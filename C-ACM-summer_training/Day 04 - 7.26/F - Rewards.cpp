#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int a[3], b[3], n;
	int an = 0, bn = 0;
	for(int i = 0; i < 3; i++)
	{
		cin>>a[i];
		an += a[i];
	}
	for(int i = 0; i < 3; i++)
	{
		cin>>b[i];
		bn += b[i];
	}
	cin>>n;
	if(an%5)
		n -= an/5+1;
	else
		n -= an/5;
	if(n*10 < bn)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}
