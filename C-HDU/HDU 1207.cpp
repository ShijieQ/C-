#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 64+5;
const int INF = 0x3f3f3f3f;
long long int F[maxn];

long long int qpow(long long int a, long long int b){
    long long int ans = 1;
    while(b){
        if(b & 1){
            ans *= a;
        }
        a = a*a;
        b >>= 1;
    }
    return ans;
}

void init(){
    F[0] = 0;
    F[1] = 1;
    F[2] = 3; 
    F[3] = 5;
    F[4] = 9;
    for(int i = 5; i < maxn; i++){
        F[i] = INF;
        for(int j = 1; j < i; j++){
            F[i] = min(F[i], abs(2*F[j] + qpow(2, i-j) - 1));
        }
    }
}

int main(){
    init();
    int n;
    while(cin>>n){
        cout<<F[n]<<endl;
    }
}