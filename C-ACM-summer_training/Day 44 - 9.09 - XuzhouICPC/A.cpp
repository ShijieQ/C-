#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e6+5;
const int mod = 1e9+7;

long long int cal(int a, long long int k){
    if(k < 0){
        return 1;
    }
    long long int ans = 1;
    while(k){
        if(k&1){
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        k >>= 1;
    }
    ans %= mod;
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, k;
        scanf("%d%d", &n, &k);
        long long int sum = cal(2, 1LL*n*k);
        cout<<sum<<endl;
        long long int cnt = ((cal(2, k+1) - 2 + cal(2, k*(n-2)))*n*2 - cal(n, n-k))%mod;
        cout<<cnt<<endl;
        printf("%lld\n", (sum-cnt)%mod);
    }
}