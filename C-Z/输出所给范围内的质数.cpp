#include<stdio.h>
int main()
{
	int a,b,c,d = 0;
	printf("Please input the maximum range:");
	scanf("%d",&c);
	for(a = 2;a <= c;a++)
	{
		for(b = 2;b <= a;b++)
		{
		  if(a % b == 0 && a != b)
		  {
			break;
		  }
		  if(a == b)
		  {
		  	printf("%d	",a);
			d++;
		    if(d % 12 == 0)
		    {
		  	printf("\n");
		    }
		  }
	    }
	}
	printf("\nThe total number is: %d",d);
	return 0;
}
