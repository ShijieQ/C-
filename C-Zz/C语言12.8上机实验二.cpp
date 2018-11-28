#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
void random(int a[])
{
	srand(time(0));
	for(int i = 0; i < 1000; i++)
	{
		a[i] = rand()%10001+1;
	}
}
int main()
{
	int a[1000];
	random(a);
/*	for(int i = 0; i < 1000; i++)
	{
		printf("%5d",a[i]);
	} */
	sort(a,a+1000);
	int count = 1;
	for(int m = 0;m < 1000; m++)
    {
		if(a[m] == a[m+1])
			count++;
		else
        {
			printf("%d出现了%d次\n", a[m],count);
			count = 1;
		}
    }
}
