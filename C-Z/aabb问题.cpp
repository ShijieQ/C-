/*�˳�����Ϊ�˼����������ͬaabb��Ϊ��ȫƽ��������λ��*/ 
#include<stdio.h>
#include<math.h>
int main()
{
	int count = 0;
	for(int a = 1;a <= 9;a++)
	 for(int b = 1;b <= 9;b++)
	 {
	 	int n = a * 1100 + b * 11;
	 	int m = floor(sqrt(n) + 0.5);//�˴�floor����Ϊȡ����+ 0.5Ŀ����Ϊʵ���������롣
		/*Ҳ��ʹ��floor(sqrt(n)),�����ھ���������ܻ������*/ 
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
