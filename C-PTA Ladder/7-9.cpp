#include<set>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
//int c[51][10005];
set<int> flag[51];
set<int>::iterator finding;
int main()
{
	int N,num,c;
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		cin>>num; 
		for(int j = 0; j < num; j++)
		{
			cin>>c;
			flag[i].insert(c);
		}
	}
	int K;
	cin>>K;
	for(int i = 0; i < K; i++)
	{
		int a,b,rate = 0;
		cin>>a>>b;
		for(finding = flag[a-1].begin(); finding != flag[a-1].end(); finding++)
			if(flag[b-1].find(*finding) != flag[b-1].end())
				rate++;
		printf("%.2f%%\n",rate*1.0/(flag[a-1].size()+flag[b-1].size()-rate)*100);
	}
	return 0;
} 
