#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 10;
void print(double a[]);
double average(double a[]);
double max_num(double a[]);
void found(double a[]);
void sort1(double a[]);
int main()
{
	double array[maxn];
	for(int i = 0; i < maxn; i++)
		scanf("%lf",&array[i]);
	sort1(array);
	print(array);
	printf("average = %f\n",average(array));
	printf("max_num = %f\n",max_num(array));
	found(array);
	return 0;
}
void print(double a[])
{
	for(int i = 0; i < maxn; i++)
		printf("%.2f ",a[i]);
	printf("\n");
}
double average(double a[])
{
	double sum;
	for(int i = 0; i < maxn; i++)
		sum += a[i];
	return sum/maxn;
}
double max_num(double a[])
{
	double b = -1000000000.0;
	for(int i = 0; i < maxn; i++)
	{
		if(a[i] > b)
		{
			double temp;
			temp = a[i];
			a[i] = b;
			b = temp;
		}
	}
	return b;
}
void found(double a[])
{
	int flag = 0;
	double num;
	printf("Please input a number what you want to find:");
	scanf("%lf",&num);
	for(int i = 0; i < maxn; i++)
		if(fabs(a[i] - num) <= 1e-6) 
		{
			flag = 1;
			break;
		}
	if(flag) printf("%f is existed.\n",num);
	else printf("Not found.\n"); 
}
void sort1(double a[])
{
	sort(a,a+maxn);
}
