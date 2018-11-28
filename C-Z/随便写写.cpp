#include<stdio.h>
#include<time.h>
int main()
{
	double i;
	for(i = 0; i != 10; i += 0.1)
	{	
		printf("%.1f\n", i);
		printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);
}
	return 0;
}
