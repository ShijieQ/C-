#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e3+10;
const int mod = 998244353;

long long int qpow(long long int a, long long int b){
    long long int ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main(){
    int m;
    cin>>m;
    long long int ans = qpow(3, m);
    cout<<ans<<endl;
    return 0;
}