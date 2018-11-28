#include<stdio.h>
int main()
{
	int a,b,n;
	printf("What's you want to input?:");
	scanf("%d",&n);
	for(a = 1;a <= n;a++)
	{
		printf("Please input a positive integer:");
		scanf("%d",&b);
		if(b <= 0)
		{
		    printf("Sorry,It is not a positive integer.\n");
		//	break;	
		    continue;
			//测试 break 与 continue 的 区别 
		}
		else
		{
			printf("n = %d\n",b);
		} 
	}
	return 0;
}
