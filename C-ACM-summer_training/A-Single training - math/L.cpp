#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000+5;
long long int a[maxn];

long long sol(int k, int n, int mod, long long int sum){
    int k1 = k;
    k--;
    long long int ans = 1;
    n %= mod;
    while(k){
        if(k & 1){
            ans = (ans*n) % mod;
        }
        n = (n*n) % mod;
        k >>= 1;    
    }
    // Data may be overflowed.
    ans = ((ans%mod) * (k1%mod) * (sum%mod)) % mod;
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        int n, k, mod;
        long long int sum = 0;
        scanf("%d%d%d", &n, &k, &mod);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        printf("Case %d: %lld\n", t, sol(k, n, mod, sum));
    }
}
/*
2
3 1 35000
1 2 3
2 3 35000
1 2
*/