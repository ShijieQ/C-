#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[10],max,min;
	for(int i = 0; i < 10; i++)
		scanf("%d",&a[i]);
	max = *max_element(a,a+10);
	min = *min_element(a,a+10);
	for(int i = 0; i < 10; i++)
		if(max == a[i])
		{	
			int temp;
			temp = a[i];
			a[i] = a[9];
			a[9] = temp;
			break;
		}
	for(int i = 0; i < 10; i++)
		if(min == a[i])
		{
			
			int temp;
			temp = a[i];
			a[i] = a[0];
			a[0] = temp;
			break;
		}
	for(int i = 0; i < 10; i++)
		printf("%4d",a[i]);
}
