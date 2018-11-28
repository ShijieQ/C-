#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

typedef struct node{
	int fa;
	int er;
}node;

int main()
{
	int n;
	node a[1005];
	cin>>n;
	int f[1005];
	memset(f, 0, sizeof(f));
	a[1].fa = 0;
	for(int i = 1; i <= n; i++)
		a[i].er = 0;
	for(int i = 2; i <= n; i++)
	{
		int temp;
		scanf("%d", &temp);
		a[temp].er++;
		a[i].fa = temp;
	}
	for(int i = 1; i <= n; i++)
	{
//		cout<<"node : "<<i<<" fa :"<<a[i].fa<<" er :"<<a[i].er<<endl;
/*		if(a[i].er)
			a[a[i].fa].er--;*/
		if(!a[i].er)
			f[a[i].fa]++;
	}
/*	for(int i = 1; i <= n; i++)
	{
		cout<<"node : "<<i<<" fa :"<<a[i].fa<<" er :"<<a[i].er<<endl;
	}*/
	/*
	for(int i = 1; i <= n; i++)
		if(a[i].er != 3)
			if(a[i].er != 0)
			{
				cout<<"No"<<endl;
				return 0;
			}
	*/
	for(int i = 1; i <= n; i++)
		if(a[i].er && f[i] < 3)
		{
			cout<<"No"<<endl;
			return 0;
		}		
	cout<<"Yes"<<endl;	
}
 
 
