#include <stdio.h>  
#include <string.h>  
int main()  
{  
    int i=1,j,n,jin,m,s;  
    int a[5][260];//ֻ���������ռ䣬ѡһ��Ϊ��ǰ�����С�  
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
                jin=s/100000000;//���ǰ���10λ��λ�����ǰ���8λһ��λ��  
                a[m][j]=s%100000000;  
            }  
        }  
        i=259;  
        while(!a[n%5][i])  
           i--;  
        printf("%d",a[n%5][i]);//ͷ8λ���ܲ���8λ��ǰ�����  
        i--;  
        while(i>=0)  
        {  
            printf("%08d",a[n%5][i]);  
            i--;  
        }  
        printf("\n");//ע������˻���.  
    }  
    return 0;  
} 
