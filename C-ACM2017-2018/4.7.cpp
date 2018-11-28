#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int num[101];
	cin>>n;
	while(n--)
	{
		int N,K;
		int flag = 1;
		cin>>N>>K;
		for(int i = 1; i <= N; i++)
			cin>>num[i];
		sort(num,num+(N+1));
		for(int i = 1; i <= N; i++)
		{
			while(num[i] != i && num[i] < i)
			{
				num[i]+=K;
				sort(num+i,num+(N+1));
			}
			if(num[i] > i)
			{
				flag = 0;
				break;
			}
		}
		if(flag) cout<<"Jerry"<<endl;
		else cout<<"Tom"<<endl;
	}
	return 0; 
}
