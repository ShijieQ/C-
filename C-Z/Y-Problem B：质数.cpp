/*Problem B:
	���ú��������100��200֮����������� */
#include<stdio.h>
#include<math.h>
int judgeprime(int a);//�����ж������ĺ��� 
int main()
{
	int count = 0;//����һ��������������ʼֵΪ 0�����ڻ��С� 
	for(int j = 2; j < 300 ; j++)
	{
		if(judgeprime(j) == 1)
		{
			printf("%5d",j);
			count++;
			if(count % 5 == 0)// ÿ�� 5 ������ 
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
			return 0;//�����һ���ܳ��ģ�����ֵ 0 ���Ϊ������,ͬʱ��ʱ����������  
	}
	return 1;//ѭ���������Ҳ����������ģ���Ϊ����������ֵΪ 1 . 
} 
