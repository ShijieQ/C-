#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e6+100;
int e[maxn];
long long int ans[maxn];

void init(){
    e[0] = e[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!e[i]){
            for(int j = i; j < maxn; j += i){
                if(!e[j])
                    e[j] = j;
                e[j] = 1LL*e[j]*(i-1)/i;
            }
        }
    }
    ans[0] = ans[1] = 0;
    for(int i = 2; i < maxn; i++){
        ans[i] = ans[i-1] + e[i];
    }
}

int main(){
    init();
    int n;
    while(scanf("%d", &n) != EOF && n){
        printf("%lld\n", ans[n]);
    }
}