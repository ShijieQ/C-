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
const int maxn = 2e4+10;
int F[maxn];
int prime[maxn];
int num = 0;

void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            prime[++num] = i;
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
}

int main(){
    init();
    int n;
    cin>>n;
    bool flag = 0;
    for(int i = 1; i <= num && !flag && prime[i] < n; i++){
        for(int j = 1; j <= num && !flag && prime[j] < n; j++){
            int k = n - prime[i] - prime[j];
            if(k > 0 && !F[k]){
                flag = 1;
                cout<<prime[i]<<" "<<prime[j]<<" "<<k<<endl;
            }
        }
    }
    return 0;
}