#include<stdio.h>
int main()
{
	int a = 65;
	printf("十进制输出：%d\n",a);
	printf("八进制输出：%o\n",a);
	printf("十六进制输出：%x\n",a);
	printf("字符输出：%c\n",a);
	printf("浮点型输出：%f\n",a);
	printf("长类型浮点型输出：%lf\n",a);
	float b = 65.02452;
	printf("float : %f\n",b);//浮点型存储方式与整型数据存储方式不同，无法通过%f输出整型数据。 
	printf("double ：%lf\n",b);
	return 0;
}
