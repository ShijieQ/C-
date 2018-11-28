#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e7+10;
int prime[maxn/10];
bool F[maxn];
int ans[maxn]
int num = 0;

void init(){
    F[1] = F[0] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            prime[num++] = i;
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
}

int sol(){
    memset(prime, 0, sizeof(prime));
    for(int i = 0; i < num; i++){
        for(int k = i; k < num; k++){
            long long int tem = prime[i]*prime[k];
            if(tem > maxn)
                break;
            ans[int(tem)]++;
        }
    }
}