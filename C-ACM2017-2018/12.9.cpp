#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int *H = new int[N+1];
	for(int i = 1; i <= N; i++)
		scanf("%d",&H[i]);
	int T;
	cin>>T;
	int j = T;
	int flag;
	for(int i = 1; i <= N; i++)
		if(T % H[i] < j)
		{
			j = T % H[i];
			flag = i;
		}
	cout<<H[flag]<<endl;
}
