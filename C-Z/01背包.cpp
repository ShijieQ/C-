#include<iostream>
#include<algorithm> 
using namespace std;

const int MIN=0;

int F[200][200];//ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ

/*int max(int a,int b)  //һ����С�ȽϺ��������ڵ����ش��ڵ�I��ʱ 
{
   if(a>=b)
     return a;
   else return b;
}*/ 

int Knapsack(int n,int w[],int v[],int x[],int C)//�����ǵ���ָ�봫�ݵ�
{
	int i,j;//F[i][j] ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ
	
	for(i=0;i<=n;i++)
 		for(j=0;j<=C;j++)               
 			F[i][j]=MIN;                //��ʼ��Ϊ0
////////////////�ؼ�����//////////////////////
  	for(i=1;i<=n;i++)
    	for(j=1;j<=C;j++)//����j�Ǵ�w[i]��ʼ����������С�ڵ�i����Ʒ��������״̬ת���������±���ָ�ֵ��������
 		{
 			if(j>=w[i])
        		F[i][j]=max(F[i-1][j],F[i-1][j-w[i]]+v[i]);//����������
        	else
        		F[i][j]=F[i-1][j];
			cout<<"F["<<i<<"]["<<j<<"]="<<F[i][j]<<endl;
 		}
//////////////////////////////////////////// 

  	j=C;//ȷ����������

  	for(i=n;i>0;i--)
  	{//��֪�������������ϼ�ȥ������Ʒ������ȷ��������װ����Ʒ
  		if(F[i][j]>F[i-1][j])//�����ǰi����Ʒװ��ȥ�Ƚ�ǰi-1����Ʒװ��ȥ�ܼ�ֵ��˵���ܼ�ֵ���ı������е�i����Ʒ��
  		{
  	  		x[i]=1;
  	  		j=j-w[i];//���õ��Ľ��С���㣬��Ϊ������Ķ���ѭ�����Ѿ��������
  		}
  		else
  			x[i]=0;   
  	}

  	cout<<"ѡ�е���Ʒ��:"<<endl;

  	for(i=1;i<=n;i++)
  		cout<<x[i]<<endl;

/*Ҳ����������������е���Ʒ
  while(i)
  {
 if(F[i][j]==(F[i-1][j-w[i]]+v[i]))//������ÿ����Ʒ
 {
 cout<<i<<":"<<"v="<<v[i]<<",w="<<w[i]<<endl;
 j-=w[i];
 }
 i--;
  }  
*/

  	return F[n][C];
    
}

int main()
{
	int s;//��õ�����ֵ

  	int n,i;
  	int C;//�����������

  	int *w,*v,*x;

  	cout<<"�����뱳�����������:"<<endl;
  	cin>>C;


  	cout<<"��Ʒ��:"<<endl;
  	cin>>n;

  //n+1����Ϊ�����1��ʼ�������
  //����  ��ֵ  ����Ʒ��״̬ ����Ӧ�Ŵ浽�����У���Ʒ��1��ʼ�� 

  	w = new int[n+1]; //��Ʒ������   

  	v = new int[n+1]; //��Ʒ�ļ�ֵ

  	x = new int[n+1]; //��Ʒ��ѡȡ״̬   ѡ������1  ûѡ��Ϊ0 

  	cout<<"��ֱ�������Ʒ������:"<<endl;
  	for(i=1;i<=n;i++)
    	cin>>w[i];//w[0]�ճ�

  	cout<<"��ֱ�������Ʒ�ļ�ֵ:"<<endl;
  	for(i=1;i<=n;i++)
    	cin>>v[i];//v[0]�ճ�

  	s=Knapsack(n,w,v,x,C);  //���ú��ĺ��� 

  	cout<<"�����Ʒ��ֵΪ:"<<endl;
  	cout<<s<<endl;

  	delete []w;
  	delete []v;
  	delete []x;

  	//system("pause");
  	return 0;
   
}
