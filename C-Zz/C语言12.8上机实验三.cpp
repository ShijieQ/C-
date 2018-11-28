#include<stdio.h>
int maxn = 5;
void in(int a[],int n);
void print(int a[],int n);
void last(int a[],int n);
int main()
{
    int a[maxn][maxn];
    int sum1 = 0,sum2 = 0;
    in(*a,25);
    printf("该矩阵为:\n");
    print(*a,25);
    for(int i = 0; i < maxn; i++)
    {
        sum1 += a[i][i];
        sum2 += a[i][maxn-1-i];
    }
    printf("主对角线之和为：%d,次对角线之和为：%d",sum1,sum2);
    return 0;
}
void in(int a[],int n)
{
    int *p;
    p = &a[0];
    for(int i = 0; i < n; i++)
            scanf("%d",p+i);
}
void print(int a[],int n)
{
    int *p = a;
    int count1 = 0;
    for(int i = 0; i < n; i++)
    {
        printf("%4d ",*(p+i));
        count1++;
        if(count1 % 5 == 0)
            printf("\n");
    }
}
