#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int d;
	while(scanf("%d", &d) != EOF && d != -1)
	{
		int ans = 0;
		double h, m, s;
		double hm, ms, sh;
		for(int i = 0; i < 12; i++)
			for(int j = 0; j < 60; j++)
				for(int k = 0; k < 60; k++)
				{
					s = k*1.0 * 6;
					m = j*1.0 * 6 + k * 0.1;
					h = i*1.0 * 30 + m*1.0 / 12;
					if(hm >= d && ms >= d && sh >= d)
						ans++;
//					printf("the time is %02d : %02d : %02d   %05f, %05f, %05f \n",i, j, k, h, m, s);
				}
		printf("%.3f\n", ans*1.0/432);
	}
	return 0;
}
