#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	char T;
	scanf("%d %c",&n,&T);
	for(int i = 0; i < (int)(n*1.0/2+0.5); i++)
	{
		for(int j = 0; j < n; j++)
			printf("%c",T);
		printf("\n");
	}
	return 0;
}
