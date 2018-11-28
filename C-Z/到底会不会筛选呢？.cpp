#include<stdio.h>
int main()
{
	float a;
	scanf("%f",&a);
	printf("%9.2f\n",a);
	return 0;
	//答案.是单精度浮点型我不会让他对齐。
	//好吧，现在我会了。%9.2中9是总字符长度，.2为小数点后保留两位。 
}


