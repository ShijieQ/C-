/*Problem B:
	调用函数，输出100到200之间的所有素数 */
#include<stdio.h>
#include<math.h>
int judgeprime(int a);//声明判断质数的函数 
int main()
{
	int count = 0;//定义一个计数变量，初始值为 0，用于换行。 
	for(int j = 2; j < 300 ; j++)
	{
		if(judgeprime(j) == 1)
		{
			printf("%5d",j);
			count++;
			if(count % 5 == 0)// 每行 5 个数。 
				printf("\n"); 
		} 
	} 
}
int judgeprime(int a)
{
	double k = sqrt(a);
	for(int i = 2; i <= k; i++)
	{
		if(a % i == 0)
			return 0;//如果找一个能除的，返回值 0 标记为非素数,同时此时函数结束。  
	}
	return 1;//循环结束还找不到能整除的，就为素数，返回值为 1 . 
} 
