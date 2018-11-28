#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 4000000+5;
long long int n[maxn];
long long int b[maxn];
long long int dp[maxn];

void init(){
    n[0] = n[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!n[i]){
            for(int j = i; j < maxn; j += i){
                if(!n[j])
                    n[j] = j;
                n[j] = 1LL*n[j]*(i-1)/i;
            }
        }
    }
    for(int i = 1; i <= maxn; i++){
            for(int j = 2*i; j <= maxn; j+=i){
                b[j] += n[j/i]*i;
            }
        }
    for(int i = 2; i <= maxn; i++){
        dp[i] = dp[i-1] + b[i];
    }
}

int main(){
    init();
    int k;
    while(scanf("%d", &k) != EOF && k){
        printf("%lld\n", dp[k]);
    }
}