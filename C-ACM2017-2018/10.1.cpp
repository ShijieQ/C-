#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
typedef struct ord
{
	string s;
	int c,d;
}ord;

int main()
{
	int T;
	cin>>T;
	for(int k = 1; k <= T; k++)
	{
		int N;
		cin>>N;
		int *a = new int[N+1];
		int *b = new int[N+1];
		b[0] = 0;
		for(int i = 1; i <= N; i++)
		{
			scanf("%d",&a[i]);
			b[i] = b[i-1] + a[i];
		}
		ord order;
		for(int i = 1; i <= 40000; i++)
		{
			cin>>order.s;
			scanf("%d %d",&order.c,&order.d);
			if(s == "Query")
				
		}
			
		
	}
} 
