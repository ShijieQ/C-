#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN = 202020;
const int MOD = 998244353;
int fac[MAXN], facinv[MAXN];
int n, m, k;
long long quickmul(int a, int b)
{
    long long ret = 1;
    for(; b; b >>= 1, a = (long long)a * a % MOD)
        if(b & 1)
            ret = ret * a % MOD;
    return ret;
}
void init()
{
    fac[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fac[i] = (long long)fac[i - 1] * i % MOD;
    facinv[MAXN - 1] = quickmul(fac[MAXN - 1], MOD - 2);
    for(int i = MAXN - 1; i > 0; i--)
        facinv[i - 1] = (long long) facinv[i] * i % MOD;
}
long long C(int n, int m)
{
    if(n < 0 || m < 0 || m > n)
        return 0;
    return (long long)fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}
void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    int ans = 0;
    for(int c = 0; c * n <= k; c++)
    {
        if(c & 1)
            ans = (ans - C(m, c) * C(k - c * n + m - 1, m - 1) % MOD + MOD) % MOD;
        else
            ans = (ans + C(m, c) * C(k - c * n + m - 1, m - 1)) % MOD;
    }
    printf("%d\n", ans);
}
int main()
{
    init();
    int T;
    for(scanf("%d", &T); T; T--)
        solve();
    return 0;
}