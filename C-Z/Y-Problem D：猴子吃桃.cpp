/*Problem D:
	猴子吃桃 */
#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	int s = 1;
	for(int i = 1;i <= a - 1;i++)
	{
		s = 2 * (s + 1);
	}
	printf("%d",s);
}
/*根据题目提示编写程序，逆向求解。 
