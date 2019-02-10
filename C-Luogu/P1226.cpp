#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;

long long int qpow(long long int a, long long int b, long long int mod){
    long long int ans = 1;
    while(b){
        if(b & 1){
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans%mod;
}

int main(){
    long long int a, b, mod;
    cin>>a>>b>>mod;
    cout<<a<<"^"<<b<<" mod "<<mod<<"="<<qpow(a, b, mod)<<endl;
    return 0;
}