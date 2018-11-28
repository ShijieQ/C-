#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a[3];
		for(int i = 0; i < 3; i++)
			cin>>a[i];
		sort(a,a+3);
		int num = 0;
		if(a[2] - a[0] >= 2)
		{
			num = (a[2] - a[0])/2;
			a[0] += (a[2] - a[0]) / 2 * 2;
		}
		if(a[2] - a[1] >= 2)
		{
			num += (a[2] - a[1])/2;
			a[1] += (a[2] - a[1]) / 2 * 2;
		}
		if(a[2] == a[1] && a[1] == a[0])
		{
			cout<<num<<endl;
			continue;
		}
		sort(a,a+3);
		if(a[2] == a[1])
			num += 2;
		if(a[1] == a[0])
			num += 1;
//		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
		cout<<num<<endl; 
	}
	return 0;
}
