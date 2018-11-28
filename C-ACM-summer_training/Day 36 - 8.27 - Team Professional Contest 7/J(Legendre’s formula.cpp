#include <iostream>
#include <cstdio>
using namespace std;
int const maxSize=10000000;
long long ans[10000005];
int isPrime[10000005];
int primes[maxSize],l;
void init(){
    ans[0] = ans[1] = 1;
    l = 0;
    for (int i=2; i<=maxSize; i++){
        ans[i] = ans[i-1];
        if (!isPrime[i]){
            primes[l++] = i;
            if (i < 3163)
                for (int j=i*i; j<=maxSize; j+=i)
                    isPrime[j] = true;
        }
        else
            ans[i] = (ans[i] * i) % 1000000007;
    }
}
int main(){
    init();
    int n;
    while(~scanf("%d", &n) && n){
        long long num = ans[n];
        /*
            Legendre’s formula勒让德定理
            */
        for (int i=0; i<l && primes[i] <= n/2; ++i){
            int cnt = 0;
            int tn = n;
            while(tn >= primes[i]){
                tn /= primes[i];
                cnt += tn;
            }
            if (cnt % 2 == 0){
                num = (num * primes[i]) % 1000000007;
            }
        }
        printf("%lld\n", num);
    }
    return 0;
}
