#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100000+10;
const int mod = 9901;
const int INF = 0x3f3f3f3f;
int F[maxn];
int prime[maxn];
pair<long long int, long long int> fac[maxn/10];
int num = 0;
int fac_num = 0;
int A, B;

long long int qpow(long long int a, long long int b){
    long long int ans = 1;
    while(b){
        if(b&1){
            ans = ans*a%mod;
        }
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}

long long int inv(long long int a){
    return qpow(a, mod - 2)%mod;
}

void init(){
    F[0] = F[1] = 1;
    for(int i = 2 ; i < maxn; i++){
        if(!F[i]){
            prime[num++] = i;
            for(int k = 2; k*i < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
}

void cal(long long a){
    fac_num = 0;
    for(int i = 0; prime[i] < a && i < num; i++){
        int cnt = 0;
        if(a % prime[i] == 0){
            while(a % prime[i] == 0){
                a /= prime[i];
                cnt++;
            }
            fac[++fac_num].first = prime[i];
            fac[fac_num].second = cnt;
        }
    }
    if(a > 1){
        fac[++fac_num].first = a;
        fac[fac_num].second = 1;
    }
}

void solve(){
    cal(A);
    long long int ans = 1;
    for(int i = 1; i <= fac_num; i++){
        ans *= (qpow(fac[i].first, fac[i].second * B + 1) - 1) % mod * inv(fac[i].first - 1) % mod;
        ans %= mod; 
    }
    if(!A) ans = 0;
    cout<<ans<<endl;
}

int main(){
    init();
    while(scanf("%d%d", &A, &B) != EOF){
        solve();
    }
    return 0;
}
/*
15761 12337
19813 13507
19309 8
18307 8828
24902 29155
*/