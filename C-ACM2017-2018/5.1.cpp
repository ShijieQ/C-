#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[2005],b[2005],c[2005];
	int case1;
	cin>>case1;
	while(case1--)
	{
		int n;
		cin>>n;
		int min_time;
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		for(int i = 2; i <= n; i++)
			cin>>b[i];
		c[1] = a[1];
		c[2] = min(a[1]+a[2],b[2]);
		for(int i = 3; i <= n; i++)
			c[i] = min(c[i-1]+a[i],c[i-2]+b[i]);
		min_time = c[n];
		int h,m,s;
		h = min_time / 3600;
		m = (min_time - h*3600)/60;
		s = min_time % 3600 % 60;
		if(h + 8 >= 12)
			printf("%02d:%02d:%02d pm\n",(h+8-12==0)?12:(h-4),m,s);
		else
			printf("%02d:%02d:%02d am\n",h+8,m,s);
	}
	return 0;
}
