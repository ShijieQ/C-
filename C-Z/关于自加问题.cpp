/*关于for中判断出现自加问题，
一般最终判断也会实现自加。*/ 
#include<stdio.h>
int main()
{
	int i; 
	for(i = 1;i + + < 2;i++)
	 printf("%d\n",i);
	printf("%d\n",i);
 } 
