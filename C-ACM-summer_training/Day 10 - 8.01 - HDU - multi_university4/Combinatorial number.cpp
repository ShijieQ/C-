#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <windows.h>
#define LL long long
using namespace std;
LL n,m,p = 1e9+7;

LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

LL C(LL n, LL m)
{
    if(m > n) return 0;
    LL ans = 1;
    for(int i=1; i<=m; i++)
    {
        LL a = (n + i - m) % p;
        LL b = i % p;
        ans = ans * (a * quick_mod(b, p-2) % p) % p;
    }
    return ans;
}

LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
		scanf("%I64d%I64d", &n, &m);
    	double time=0;  
		double counts=0;  
		printf("%I64d\n", Lucas(max(n,m),min(n,m)));
        
    }
    return 0;
}
