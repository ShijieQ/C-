#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e7+5;
bool F[maxn];
int prime[maxn/10];
int num = 0;

void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            prime[num++] = i;
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
}

int solve(long long int n){
    int ans = 1;
    for(int i = 0; i < num && prime[i] < n; i++){
        int tem = 0;
        while(n % prime[i] == 0){
            n /= prime[i];
            tem++;
        }
        ans *= (1+tem);
    }
    if(n > 1){
        ans *= 2;
    }
    return ans;
}

int main(){
    init();
    long long int b;
    cin>>b;
    cout<<solve(b)<<endl;
    return 0;
}