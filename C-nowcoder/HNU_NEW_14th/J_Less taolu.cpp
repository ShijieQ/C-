#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
 
using namespace std;
const int maxn = 1e5+10;
const int mod = 1e9+7;
int F[maxn];
 
void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        F[i] = (1LL*i*F[i-1]%mod + 1LL*(i-1)*F[i-2]%mod)%mod;
    }
}
 
int main(){
    init();
    int n;
    cin>>n;
    cout<<F[n]<<endl;
    return 0;
}