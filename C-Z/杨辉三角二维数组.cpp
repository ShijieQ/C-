#include<stdio.h>
int a[1000][1000];
int main()
{
	int b;
	scanf("%d",&b);	
	for(int i = 0; i < b; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(i == j || j == 0)
			{
				a[i][j] = 1;
			}
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	for(int i = 0; i < b; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*#include<iostream> 
using namespace std;
 int main() 
{     
         int a[30][30],i,j,n;     
         while(cin>>n)     
           {     
                   for(i=0;i<n;i++)     
                   for(j=0;j<n;j++)     
                          {         
                                    if(j==0||i==j) 
                                     a[i][j]=1;         
                                      else 
                                      a[i][j]=a[i-1][j]+a[i-1][j-1];     
                         }     
                    for(i=0;i<n;i++)     
                    for(j=0;j<=i;j++)    
                        {         
                                   if(j==i) 
                                   cout<<a[i][j]<<endl; 
                                   else cout<<a[i][j]<<" ";    
                        }     
                    cout<<endl;     
         }        
                 return 0; 
} */ 
