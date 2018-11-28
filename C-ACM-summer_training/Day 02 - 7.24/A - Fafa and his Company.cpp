#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int a, ans = 0;
	cin>>a;
	for(int i = 1; i <= a/2; i++)
	{
		if((a-i) % i == 0)
			ans++;
	}
	cout<<ans<<endl;
 } 
