/*Problem C:
	���ú�������a + aa + aaa + ... + aa...aa(n��a) */
#include<stdio.h>
#include<math.h> //ʹ��pow����������ͷ�ļ� 
int fn(int a,int n);//�������� 
int main()
{
	int a,n,sum = 0;//�������ж���sum��������ֵ
	scanf("%d %d",&a,&n); 
	for(int i = n; i > 0; i--)
	{
		sum = sum + fn(a,i);//��ε���fn�����õ�ÿ��ʽ���е�Ԫ��
	}
	printf("%d",sum);
} 
int fn(int a,int n)//Function������aa...a(n��a),��fn(3,2)����ֵΪ33. 
{
	int sum = 0;
	for(int i = n; i > 0; i--)
		sum = sum + a * pow(10,i-1);//����pow�������ݴΣ�ͨ��λ���ݼ�����ӵõ��������֡� 
	return sum;
} 
