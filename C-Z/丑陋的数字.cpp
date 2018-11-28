#include<stdio.h>
int main()
{
	int count = 1,i;
	for(i = 2; ;i++)
	{
		if(i % 5 == 0 ||i % 3 == 0||i % 2 == 0)
		{ 
			count++;
			printf("%d\n",i);
		} 
		if(count == 1500)
		 break;
	}
	printf("The 1500'th ugly number is %d.",i);
	return 0;
}
