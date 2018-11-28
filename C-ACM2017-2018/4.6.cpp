#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int case1 = 0;
	while(n--)
	{
		char a[10],b[10],c[4],d[4];
		scanf("%s %s",a,b);
		int k = 0;
		for(int i = 2; i < 4; i++,k++)
		{
			c[k] = a[i];
			d[k] = b[i];
		}
		if(a[0] == b[0])
			cout<<"case "<<++case1<<"= ";
		if(a[0] < b[0])
			cout<<"case "<<++case1<<"< ";
		if(a[0] > b[0])
			cout<<"case "<<++case1<<"> ";
		
	}
} 
