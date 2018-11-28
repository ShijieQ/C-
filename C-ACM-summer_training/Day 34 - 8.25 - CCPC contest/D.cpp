#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

void cal(long long a)
{
    if (a % 2 == 1)
    {
        long long int k = (a - 1) / 2;
        long long int b = 2 * k * (k + 1);
        long long int c = 2 * k * (k + 1) + 1;
        printf("%lld %lld\n", b, c);
    }
    else if (a % 8 == 0)
    {
        long long int k = a / 8;
        long long int b = 16 * k * k - 1;
        long long int c = 16 * k * k + 1;
        printf("%lld %lld\n", b, c);
    }
    else if (a % 2 == 0)
    {
        if (a == 4)
        {
            cout << "3 5" << endl;
        }
        else
        {
            long long int a1 = a;
            while (!(a & 1))
            {
                a >>= 1;
            }
            long long int beishu = a1 / a;
            long long int k = (a - 1) / 2;
            long long int b = beishu * (2 * k * (k + 1));
            long long int c = beishu * (2 * k * (k + 1) + 1);
            printf("%lld %lld\n", b, c);
        }
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
