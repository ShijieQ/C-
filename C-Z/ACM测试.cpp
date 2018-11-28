#include<stdio.h>
#include<math.h>
#include<time.h> 
int judgeprime(int x);
int main()
{
	int a,c,i = 0;
	while(printf("Please input the range:"),scanf("%d",&c) != EOF)
	{
		for(a = 2;a <= c;a++)
		{
			if(judgeprime(a))
			{
				printf("%d	",a);
				i++;
				if(i % 12 == 0)
				 printf("\n");
			}
		}
		printf("\nThe sum = %d.\n",i);
		printf("the time uses %lf sec.\n",(double)clock()/CLOCKS_PER_SEC); 
	}
} 
 int judgeprime(int x)
 {
 	double p = sqrt(x);
 	for(int i = 2;i <= p;i++)
 	{
	   if(x % i == 0) 
	    return 0;
    }
 	return 1;
 }
