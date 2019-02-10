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
const int mod = 1e9+7;

long long int qpow(long long int a, long long int b){
    long long int ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a)%mod;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans%mod;    
}

int main(){
    long long int inv6 = qpow(6, mod - 2);
    long long int k;
    cin>>k;
    long long int ans = 0;
    for(long long int i = 0; i*i <= k; i++){
        long long int temp = sqrt(k - i*i);
        ans = (ans + i*i%mod*temp%mod + (temp*(temp+1)%mod*(2*temp+1)%mod*inv6%mod))%mod;
    }
    cout<<(ans*4)%mod<<endl;
    return 0;
}