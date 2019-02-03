#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100;
bool t[maxn], u[maxn];

long long int qpow(long long int a, long long int b){
    long long int ans = 1;
    while(b){
        if(b & 1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main(){
    long long int a, b;
    long long int cnt = 0;
    while(scanf("%lld%lld", &a, &b) != EOF){
        long long int temp = b;
        for(int i = 0; i < maxn; i++){
            t[i] = a%2;
            u[i] = b%2;
            a >>= 1; b >>= 1;
        }
        int i = maxn - 1;
        while(i >= 0 && t[i] == u[i]){
            i--;
        }
        long long int ans = (qpow(2, i+1) - 1) | temp;
        cout<<ans<<endl;
    }
    return 0;
}