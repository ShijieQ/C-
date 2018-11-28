/*Problem C:
	调用函数，求a + aa + aaa + ... + aa...aa(n个a) */
#include<stdio.h>
#include<math.h> //使用pow函数需引用头文件 
int fn(int a,int n);//声明函数 
int main()
{
	int a,n,sum = 0;//主函数中定义sum计算所求值
	scanf("%d %d",&a,&n); 
	for(int i = n; i > 0; i--)
	{
		sum = sum + fn(a,i);//多次调用fn函数得到每个式子中的元素
	}
	printf("%d",sum);
} 
int fn(int a,int n)//Function：返回aa...a(n个a),如fn(3,2)返回值为33. 
{
	int sum = 0;
	for(int i = n; i > 0; i--)
		sum = sum + a * pow(10,i-1);//调用pow函数求幂次，通过位数递减，相加得到所用数字。 
	return sum;
} 
