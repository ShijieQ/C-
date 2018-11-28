/*
	精度问题要注意！
		*/ 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int h, m;
		char s;
		double time;
		scanf("%d %d UTC%c%lf", &h, &m, &s, &time);
		h -= 8;
		if(h < 0)
			h+=24;
		if(s == '+')
		{
			h += (int)time;
			m += (time*10 - ((int)time)*10)*6;
			if(m >= 60)
			{
				m-=60;
				h++;
			}
			if(h >= 24)
				h-=24;
		}
		else
		{
			m -= (time*10 - ((int)time)*10)*6;
			h -= (int)time;
			if(m < 0)
			{
				m+=60;
				h--;
			}
			if(h < 0)
				h+=24; 
		}
		printf("%02d:%02d\n", h, m);
	}
} 
