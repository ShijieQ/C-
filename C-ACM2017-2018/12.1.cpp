#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct settle
{
	int H;
	int R;
	int T;
}settle;

int main()
{
	int N;
	cin>>N;
	settle s[21];
	int Hmax = 0;
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d %d",&s[i].H,&s[i].R,&s[i].T);
		if(s[i].H > Hmax)
			Hmax = s[i].H;
	}
	int time[100*1825 + 5];
	memset(time,0,sizeof(time));
	for(int i = 1; i <= N; i++)
	{
		if(s[i].R < s[i].T)
		{
			int k = 0;
			for(int k = 0,j = 0; j < s[i].T + k * s[i].H && j <= Hmax*1825; k++)
			{
				for(j = s[i].R + k * s[i].H + 1; j < s[i].T + k * s[i].H && j <= Hmax*1825; j++)
				{
					time[j] = 1;
				}
			}
		}
		if(s[i].R > s[i].T)
		{
			for(int k = 0,j = 0,l = 0;l <= s[i].H + k * s[i].H && l <= Hmax*1825 ; k++)
			{
				for(j = k * s[i].H; j < s[i].T + k * s[i].H && j <= Hmax*1825; j++)
					time[j] = 1;
				for(l = s[i].R + k * s[i].H + 1; l <= s[i].H + k * s[i].H && l <= Hmax*1825; l++)
					time[l] = 1;
			}
		}
	}
	int i;
	for(i = 0; i <= Hmax*1825; i++)
		if(time[i] == 0)
		{
			cout<<i<<endl;
			break;
		}
	if(i == Hmax*1825 + 1)
		cout<<"impossible"<<endl;
	return 0;
}
