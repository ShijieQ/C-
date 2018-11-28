#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e6+5;
const int mod = 1e9+7;
bool F[maxn];
int arr[maxn];
int prime[maxn/10];
int num = 0;
int k = 0;

long long int get(long long int x, long long int y) {
    long long int cnt = x / y;
    return ((y * y + y)%mod * (cnt * (cnt + 1) * (2 * cnt + 1) / 6)%mod)%mod;
}

void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            prime[num++] = i;
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
}

void cal(int a){
    k = 0;
    memset(arr, 0, sizeof(arr));
    for(int i = 0; prime[i] < a && i < num; i++){
        int cnt = 0;
        if(a % prime[i] == 0){
            arr[k++] = prime[i];
            while(a % prime[i] == 0){
                a /= prime[i];
            }
        }
    }
    if(a > 1)
        arr[k++] = a;
}

int main(){
    init();
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF){
        cal(m);
        long long int ans = 0;
        long long int sum = (1LL*n*(n+1)*(2*n+1)/6%mod + 1LL*(1+n)*n/2%mod)%mod;
        for(int i = 1; i < (1 << k); i++) {  
            long long int res = 0, cnt = 1;
            for(int j = 0; j < k; j++) {
                if(i & (1 << j)) {
                    cnt *= arr[j];
                    res++;
                }
            }
            if(res & 1) 
                ans += get(m, cnt);  
            else 
                ans -= get(m, cnt);
        }
        sum %= mod;
        ans %= mod;
        printf("%lld\n", sum - ans);
    }
}