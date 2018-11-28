#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int min,max,a[20],i = 0;
	int min1,max1,sum = 0;
	min1 = max1 = 0;
	while(scanf("%d",&a[i]) != EOF && getchar() != '\n')
		i++;
	min=*min_element(a,a+20);
	for(int j = 0;j < 20;j++)
		if(a[j] == min)
			min1++;
	max=*max_element(a,a+20);
	for(int j = 0;j < 20;j++)
	{
		if(a[j] == max)
			max1++;
		sum += a[j];
	}
	printf("count=%d,average=%.2f\n",20-min1-max1,(double)(sum-min1*min-max1*max)/(20-min1-max1));
}
