#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const long long maxn = 1e6+5;
int F[maxn];
int prime[maxn];
int num = 0;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < maxn; i++){
        F[i] = 1;
    }
    F[0] = F[1] = 0;
    for(int i = 2 ; i < maxn; i++){
        if(F[i]){
            prime[num++] = i;
            for(int k = 2; k*i < maxn; k++){
                F[i*k] = 0;
            }
        }
    }
}

int main(){
    init();
    for(int i = 0; i < num; i++){
        cout<<prime[i]<<endl;
    }
}