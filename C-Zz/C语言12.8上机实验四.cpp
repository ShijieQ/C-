#include<stdio.h>
void Ra(int a[3][3])
{
    int i,j;
    for (j=0;j<3;j++)
        for (i=0;i<3;i++)
            scanf("%d",&a[j][i]);
}
void Pa(int a[3][3])
{
    int i,j;
    printf("该矩阵为：\n");
    for (j=0;j<3;j++)
    {
        for (i=0;i<3;i++)
            printf("%d ",a[j][i]);
        printf("\n");
    }
}
void Ta(int a[3][3])
{
    int i,j,t;
    for (j=0;j<3;j++)
        for (i=0;i<=j;i++)
        {
            t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
}
main()
{
    int a[3][3];
    Ra(a);
    Pa(a);
    Ta(a);
    printf("转置后");
    Pa(a);
    return 0;
}
