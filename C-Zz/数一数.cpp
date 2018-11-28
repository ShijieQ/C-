#include <cstdio>
#define ll long long
using namespace std;

ll sol(ll n) {
    ll ans = 0, base = 1, l = 0, cur = 0, r = 0;
    if (n <= 0) {
        return 0;
    }
    while (n / base != 0)
    {
        l = n - (n / base) * base;
        cur = (n / base) % 10;
        r = n / (base * 10);
        if (cur < 3)
        {
            ans += base == 1 ? r * base : r * base / 2;
        } else if (cur == 3)
        {
            ans += base == 1 ? r * base + l + 1 : (r * base + l + 1) / 2;
        } else if (cur > 3)
        {
            ans += base == 1 ? (r + 1) * base : (r + 1) * base / 2;
        }
        base *= 10;
    }
    return ans;
}

int main() {
    int T;
    ll n;
    scanf("%d", &T);
    while (T --)
    {
        scanf("%lld", &n);
        printf("%lld\n", sol(n));
    }
}
