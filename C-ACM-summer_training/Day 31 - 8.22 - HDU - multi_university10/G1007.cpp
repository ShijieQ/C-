#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100000+10;
const int mod = 998244353;
long long F[maxn];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    F[0] = 1;
    F[1] = 0;
    F[2] = 0;
    for(int i = 3; i < maxn; i++){
        F[i] = ((i-3) * F[i-1] + (i-2) * (2*F[i-2] + F[i-3]))%mod;
    }
}

int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<F[n]<<endl;
    }
}