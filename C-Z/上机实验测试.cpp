#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	double array[10];
	double sum;
	for(int i = 0; i < 10; i++)	
	{
		scanf("%lf",&array[i]);
		sum += array[i];
	}
	for(int i = 0; i < 10; i++)
		printf("%f",array[i]);
	sort(array,array+10);
	return 0;
}
