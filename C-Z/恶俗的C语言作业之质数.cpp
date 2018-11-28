#include<stdio.h>
int main()
{
	int a,b,c; 
	for(a = 100;a <= 1000;a++)
	{
		for(b = 2;b <= a;b++)
		{
		  if(a % b == 0 && a != b)
		  {
			break;
		  }
		  if(a == b)
		  {
		  	printf("   %d",a);
			c++;
		    if(c % 5 == 0)
		    {
		  	printf("\n");
		    }
		  }
	    }
	}
}
