#include <cstdio>
/*
    求某数倒数的循环节长度。
                            */
int calc(int a)
{
    while (a % 2 == 0)
    {
        a /= 2;
    }
    while (a % 5 == 0)
    {
        a /= 5;
    }
    if (a == 1)
    {
        return 0;
    }
    int ans = 1, res = 10;
    while (res % a != 1)
    {
        res = res * 10 % a;
        ans ++;
    }
    return ans;
}

int main()
{
    int a;
    while(scanf("%d", &a) != EOF)
    {
        printf("%d\n", calc(a));
    }
}
