#include<stdio.h>
#include<string.h>
int main()
{
    char s1[100],s2[100];
    int num1[31],num2[31],len1,len2,i,j;
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    printf("please int fist number\n");
    scanf("%s",s1);
    printf("please int secound number\n");
    scanf("%s",s2);
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=len1-1,j=0; i>=0 ;i--)
        {
            num1[j]=s1[i]-48;
            j++;
        }
    for(i=len2-1,j=0; i>=0 ;i--)
        {
            num2[i]=s2[j]-48;
            j++;
        }
    for(i=0;i<(len2>len1?len2:len1);i++)
       {
           num1[i]+=num2[i];
           if(num1[i]>9)
           {
               num1[i+1]+=1;
               num1[i]-=10;
           }

       }
    if(num1[i])
        for(j=i;j>-1;j--)
            printf("%d",num1[j]);
    else
        for(j=i-1;j>-1;j--)
            printf("%d",num1[j]);

        return 0;
}
