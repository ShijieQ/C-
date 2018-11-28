#include<stdio.h>
//#define pi 3.14159 
int main()
{
	//const double pi = 3.14159;
	double r;
	scanf("%lf",&r);
	//pi = 3; 
	//如果对常量进行重新赋值会报错。 
	printf("area = %lf",pi * r * r);
	return 0;
	//在define与const常量定义时，趋向于后者，更为严谨，错误率低。 
	
 } 
