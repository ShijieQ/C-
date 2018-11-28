#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

void cal(long long a)
{
    if (a % 2 == 1)
    {
        long long int k = 1;
        long long int b = (a * a / k - k) / 2;
        long long int c = (a * a / k + k) / 2;
        printf("%lld %lld\n", b, c);
    }
    else
    {
        long long int k = 2;
        long long int b = (a * a / k - k) / 2;
        long long int c = (a * a / k + k) / 2;
        printf("%lld %lld\n", b, c);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long int n, a;
        scanf("%lld %lld", &n, &a);
        if (n > 2 || n == 0)
        {
            printf("-1 -1\n");
        }
        else if (n == 2)
        {
            cal(a);
        }
        else if (n == 1)
        {
            printf("1 %lld", a + 1);
        }
    }
}
