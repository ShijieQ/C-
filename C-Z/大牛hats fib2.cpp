#include <stdio.h>  
#include <string.h>  
int main()  
{  
    int i=1,j,n,jin,m,s;  
    int a[5][260];//只用五行做空间，选一行为当前计算行。  
    while(scanf("%d",&n)!=EOF)  
    {  
        memset(a,0,sizeof(a));  
        a[1][0]=a[2][0]=a[3][0]=a[4][0]=1;  
        for(i=5;i<=n;i++)
        {  
            jin=0;  
            m=i%5;  
            for(j=0;j<260;j++)  
            {  
                s=a[0][j]+a[1][j]+a[2][j]+a[3][j]+a[4][j]+jin-a[m][j];  
                jin=s/100000000;//不是按照10位进位，而是按照8位一进位。  
                a[m][j]=s%100000000;  
            }  
        }  
        i=259;  
        while(!a[n%5][i])  
           i--;  
        printf("%d",a[n%5][i]);//头8位可能不足8位提前输出。  
        i--;  
        while(i>=0)  
        {  
            printf("%08d",a[n%5][i]);  
            i--;  
        }  
        printf("\n");//注意别忘了换行.  
    }  
    return 0;  
} 
