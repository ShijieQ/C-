#include<iostream>
#include<algorithm> 
using namespace std;

const int MIN=0;

int F[200][200];//前i个物品装入容量为j的背包中获得的最大价值

/*int max(int a,int b)  //一个大小比较函数，用于当总重大于第I行时 
{
   if(a>=b)
     return a;
   else return b;
}*/ 

int Knapsack(int n,int w[],int v[],int x[],int C)//数组是当做指针传递的
{
	int i,j;//F[i][j] 前i个物品装入容量为j的背包中获得的最大价值
	
	for(i=0;i<=n;i++)
 		for(j=0;j<=C;j++)               
 			F[i][j]=MIN;                //初始化为0
////////////////关键代码//////////////////////
  	for(i=1;i<=n;i++)
    	for(j=1;j<=C;j++)//这里j是从w[i]开始，背包容量小于第i件物品重量，则状态转换方程中下标出现负值，无意义
 		{
 			if(j>=w[i])
        		F[i][j]=max(F[i-1][j],F[i-1][j-w[i]]+v[i]);//建立背包表
        	else
        		F[i][j]=F[i-1][j];
			cout<<"F["<<i<<"]["<<j<<"]="<<F[i][j]<<endl;
 		}
//////////////////////////////////////////// 

  	j=C;//确定背包容量

  	for(i=n;i>0;i--)
  	{//已知背包容量，不断减去最大的物品重量来确定背包中装的物品
  		if(F[i][j]>F[i-1][j])//如果将前i个物品装进去比将前i-1个物品装进去总价值大，说明总价值最大的背包中有第i个物品。
  		{
  	  		x[i]=1;
  	  		j=j-w[i];//不用担心结果小于零，因为在上面的二重循环中已经处理过了
  		}
  		else
  			x[i]=0;   
  	}

  	cout<<"选中的物品是:"<<endl;

  	for(i=1;i<=n;i++)
  		cout<<x[i]<<endl;

/*也可以这样输出背包中的物品
  while(i)
  {
 if(F[i][j]==(F[i-1][j-w[i]]+v[i]))//逐个输出每个物品
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
	int s;//获得的最大价值

  	int n,i;
  	int C;//背包最大容量

  	int *w,*v,*x;

  	cout<<"请输入背包的最大容量:"<<endl;
  	cin>>C;


  	cout<<"物品数:"<<endl;
  	cin>>n;

  //n+1是因为数组从1开始方便理解
  //重量  价值  和物品的状态 均对应着存到数组中，物品从1开始。 

  	w = new int[n+1]; //物品的重量   

  	v = new int[n+1]; //物品的价值

  	x = new int[n+1]; //物品的选取状态   选中则是1  没选中为0 

  	cout<<"请分别输入物品的重量:"<<endl;
  	for(i=1;i<=n;i++)
    	cin>>w[i];//w[0]空出

  	cout<<"请分别输入物品的价值:"<<endl;
  	for(i=1;i<=n;i++)
    	cin>>v[i];//v[0]空出

  	s=Knapsack(n,w,v,x,C);  //调用核心函数 

  	cout<<"最大物品价值为:"<<endl;
  	cout<<s<<endl;

  	delete []w;
  	delete []v;
  	delete []x;

  	//system("pause");
  	return 0;
   
}
