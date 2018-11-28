#include<stdio.h>
// static定义静态变量，退出函数体不会被释放内存 
int fun(int a)
{
	static int f = 1;
	f = f * a;
	return f;
}
int main()
{
	int i,b;
	scanf("%d",&b);
	for(i = 1;i <= b;i++)
	  printf("%d ! = %d\n",i,fun(i));
	return 0;
 } 
