#include<stdio.h>
// static���徲̬�������˳������岻�ᱻ�ͷ��ڴ� 
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
