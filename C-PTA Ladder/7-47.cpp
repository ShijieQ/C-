#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int day,month,year;
	scanf("%d-%d-%d",&month,&day,&year);
	printf("%d-%02d-%02d\n",year,month,day);
	return 0;
}
