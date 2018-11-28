#include<stdio.h>
int main()
{
    double array[10];
    double *p;
    double max1,min1;
    double sum;
    for(int i = 0; i < 10; i++)
        scanf("%lf",&array[i]);
    p = &array[0];
    for(int i = 0; i < 10; i++)
        printf("array[%d] address is %d.\n",i,p+i);
    max1 = array[0];
    for(int i = 1; i < 10; i++)
        if(max1 < array[i])
            max1 = array[i];
    min1 = array[0];
    for(int i = 1; i < 10; i++)
        if(min1 > array[i])
            min1 = array[i];
    printf("The max = %.2f, The min = %.2f.\n",max1,min1);
    for(int i = 0; i < 10; i++)
        sum += *(p+i);
    printf("The average is %f.\n",sum/10);
    for(int i = 0; i < 9; i++)
        for(int j = i+1; j < 10; j++)
            if(*(p+i) > *(p+j))
            {
                double t = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = t;
            }
    printf("\nAfter ranking:\n");
    for(int i = 0; i < 10; i++)
        printf("%.2f ",*(p+i));
    return 0;
}
