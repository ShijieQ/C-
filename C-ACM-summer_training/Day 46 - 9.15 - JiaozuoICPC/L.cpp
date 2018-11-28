#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int mod = 1e9;

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
    return qpow(a, mod-2);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        long long int n;
        cin>>n;
        long long int ans = (qpow(3, n) - 2*(n-2)%mod*qpow(3, n-2)%mod - 1 + n-2 + mod)%mod;
        cout<<ans<<endl;
    }
}