/*此程序是为了计算出所有形同aabb且为完全平方数的四位数*/ 
#include<stdio.h>
#include<math.h>
int main()
{
	int count = 0;
	for(int a = 1;a <= 9;a++)
	 for(int b = 1;b <= 9;b++)
	 {
	 	int n = a * 1100 + b * 11;
	 	int m = floor(sqrt(n) + 0.5);//此处floor函数为取整，+ 0.5目的是为实现四舍五入。
		/*也可使用floor(sqrt(n)),但由于精度问题可能会产生误差。*/ 
	 	if(m * m == n)
	 	 {
		  printf("%d	",n);
	 	  count++;
	     }
	 }
	if(!count)
	  printf("No answer.\n");
	return 0;
 } 
